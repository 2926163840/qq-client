#include "dbmanager.h"
#include <QCoreApplication>

DBManager::DBManager(QObject *parent)
    : QObject{parent}
{}

DBManager::~DBManager()
{
}
//获取数据库管理实例
DBManager *DBManager::getDBManager()
{
    static std::unique_ptr<DBManager>dbmana=std::make_unique<DBManager>();
    return dbmana.get();
}
//记录历史登入记录
void DBManager::saveLoginhist(const QString&useraccount,const QString&userpassword,bool auto_login,bool rememberpwd,qint64 login_time)
{
    QSqlQuery sql(db);
    //将数据插入到数据库里面如果说已经存在（CONFLICT（useraccount）冲突）则更新自动登入记住密码标志位和上次登入时间（excluded使用上次绑定的值）
    sql.prepare(R"(INSERT INTO logintable(useraccount,userpassword,auto_login,rememberpwd,lastlogintime)
                                    VALUES(:useraccount,:userpassword,:auto_login,:rememberpwd,:lastlogintime)
                                    ON CONFLICT(useraccount) DO UPDATE SET auto_login=excluded.auto_login,rememberpwd=excluded.rememberpwd,lastlogintime=excluded.lastlogintime;)");
    //绑定参数
    sql.bindValue(":useraccount",useraccount);
    sql.bindValue(":userpassword",userpassword);
    sql.bindValue(":auto_login",auto_login);
    sql.bindValue(":rememberpwd",rememberpwd);
    sql.bindValue(":lastlogintime",login_time);
    sql.exec();
}
//是否自动登入
void DBManager::getLoginHistory()
{
    QSqlQuery sql(db);
    std::shared_ptr<QList<LoginHistory>> lsr=std::make_shared<QList<LoginHistory>>();
    //根据时间顺序倒叙排序获取历史登入信息
    sql.exec("SELECT auto_login,rememberpwd,useraccount,userpassword FROM logintable ORDER BY lastlogintime DESC;");
    while(sql.next())
    {
        //获取一行数据追加到list容器中
        QString account=sql.value("useraccount").toString();
        QString password=sql.value("userpassword").toString();
        bool auto_login=sql.value("auto_login").toBool();
        bool rememberpwd=sql.value("rememberpwd").toBool();
        lsr->emplace_back(account,password,auto_login,rememberpwd);
    }
    emit returnLoginHistory(lsr);
}
//播种会话游标
void DBManager::sowConvSeq(const qint64 userid,const std::shared_ptr<QList<qint64>>&convid)
{
    QSqlQuery sql(db);
    //sql语句
    QString sql_before="insert into convseqtable(seqowern,convid,lastconvseq) values(?,?,0)";
    QString sql_after=",(?,?,0)";
    QString sql_finally=" ON CONFLICT(seqowern,convid) DO NOTHING";
    QString sql_str;
    //提前开辟字符串内存减少拷贝
    sql_str.reserve(sql_before.size()+((convid->count()-1)*sql_after.size())+sql_finally.size());
    sql_str+=sql_before;
    //拼接sql语句(种子游标为0)
    for(int i=0;i<convid->count()-1;i++)
    {
        sql_str+=sql_after;
    }
    sql_str+=sql_finally;
    sql.prepare(sql_str);
    int pos=0;
    //绑定所有数据
    for(const auto convidrow:*convid)
    {
        sql.bindValue(pos++,userid);
        sql.bindValue(pos++,convidrow);
    }
    //执行sql语句
    sql.exec();
}
//播种通知游标
void DBManager::sowNoticeSeq(const qint64 userid)
{
    QSqlQuery sql(db);
    //用户为首次登入初始化通知游标为0
    sql.prepare("insert into noticeseqtable(userid) values(?) ON CONFLICT(userid) DO NOTHING");
    sql.bindValue(0,userid);
    sql.exec();
}
//获取会话信息(初始化会话连续游标)
void DBManager::getConvInfo(const qint64 userid,const std::shared_ptr<QList<qint64>>&convid)
{
    QSqlQuery sql(db);
    //sql语句
    QString sql_before="select convid,IFNULL(lastconvseq,0) AS lastconvseq from convseqtable where seqowern=? AND convid IN(?";
    QString sql_after=",?";
    QString sql_finally=")";
    QString sql_str;
    //提前开辟字符串内存减少拷贝
    sql_str.reserve(sql_before.size()+((convid->count()-1)*sql_after.size())+sql_finally.size());
    sql_str+=sql_before;
    //根据会话id信息拼接sql语句(临时表)
    for(qint64 i=0;i<convid->count()-1;i++)
    {
        sql_str+=sql_after;
    }
    sql_str+=sql_finally;
    sql.prepare(sql_str);
    int pos=0;
    //绑定序列拥有者
    sql.bindValue(pos++,userid);
    //给临时表填数据
    for(const auto convidrow:*convid)
    {
        sql.bindValue(pos++,convidrow);
    }
    //执行sql
    sql.exec();
    //会话信息链表
    std::shared_ptr<QList<ConvSLInfo>> lsr=std::make_shared<QList<ConvSLInfo>>();
    while(sql.next())
    {
        qint64 lastconvseq=sql.value("lastconvseq").toLongLong();
        qint64 convid=sql.value("convid").toLongLong();
        //将会话信息插入哈希表中        ConvInfo
        convinfohash.emplace(convid,lastconvseq);
        lsr->emplace_back(convid,lastconvseq);
    }
    //读完数据发出信号返回
    emit returnConvInfo(lsr);

}
//获取通知信息(初始化用户通知游标和同步游标)
void DBManager::getNoticeInfo(const qint64 userid)
{
    QSqlQuery sql(db);
    //通知信息
    NoticeSLInfo lsr;
    sql.prepare("select IFNULL(lastnoticeseq,0) AS lastnoticeseq,IFNULL(lastsyncseq,0) AS lastsyncseq from noticeseqtable where userid=?");
    sql.bindValue(0,userid);
    sql.exec();
    if(sql.next())
    {
        lsr.noticeseq=sql.value("lastnoticeseq").toLongLong();
        lsr.syncseq=sql.value("lastsyncseq").toLongLong();
        //将连续通知序列和同步序列放到结构体里面
        noticeif.noticeseq=lsr;
        //读到数据信号返回数据
        emit returnNoticeInfo(lsr);
    }
}

//保存聊天消息到本地
void DBManager::saveOfflineMes(const qint64 userid,const std::shared_ptr<QList<Mes>>&mesinfo)
{
    QSqlQuery sql(db);
    //sql语句（upsert：uuid存在则更新 不存在则插入）
    QString sql_before="insert into messagetable(convid,convseq,sendid,content,sendtime,uuid,status) values(?,?,?,?,?,?,?)";
    QString sql_after=",(?,?,?,?,?,?,?)";
    //uuid冲突更新序列时间和状态
    QString sql_finally=" ON CONFLICT(uuid) DO UPDATE SET convseq=excluded.convseq,sendtime=excluded.sendtime,status=excluded.status";
    QString sql_str;
    //提前开辟字符串内存减少拷贝
    sql_str.reserve(sql_before.size()+((mesinfo->count()-1)*sql_after.size())+sql_finally.size());
    sql_str+=sql_before;
    //有几个数据插入几条消息
    for(int i=0;i<mesinfo->size()-1;i++)
    {
        sql_str+=sql_after;
    }
    sql_str+=sql_finally;
    //预处理
    sql.prepare(sql_str);
    //记录信息变化的会话
    QList<qint64>changedconvid;
    int pos=0;
    //绑定所有字段
    for(const Mes&row:*mesinfo)
    {
        sql.bindValue(pos++,row.convid);
        sql.bindValue(pos++,row.convseq);
        sql.bindValue(pos++,row.sendid);
        sql.bindValue(pos++,row.content);
        sql.bindValue(pos++,row.sendtime);
        sql.bindValue(pos++,row.uuid);
        sql.bindValue(pos++,row.status);
        //会话信息改变且不在容器中加入容器
        if(!changedconvid.contains(row.convid))
        {
            changedconvid.append(row.convid);
        }
    }
    //执行sql语句
    if(!sql.exec())
    {
        return;
    }
    //遍历会话信息改变的容器并更新会话连续序列游标
    for(const auto&convid:changedconvid)
    {
        hasnextconvseq(userid,convid);
    }
}

//保存通知消息到本地
void DBManager::saveNoticeMes(const std::shared_ptr<QList<Notice>>&mesinfo)
{
    QSqlQuery sql(db);
    //sql语句   通知已经存在更新通知状态和同步序列
    QString sql_before="insert into noticetable(userid,userseq,syncseq,bindid,type,status,payload,sendtime) values(?,?,?,?,?,?,?,?)";
    QString sql_after=",(?,?,?,?,?,?,?,?)";
    QString sql_finally=" ON CONFLICT(userid,bindid) DO UPDATE SET status=excluded.status,syncseq=excluded.syncseq";//bind是请求id是唯一的
    QString sql_str;
    //提前开辟字符串内存减少拷贝
    sql_str.reserve(sql_before.size()+((mesinfo->count()-1)*sql_after.size())+sql_finally.size());
    sql_str+=sql_before;
    //拼接sql语句
    for(int i=0;i<mesinfo->count()-1;i++)
    {
        sql_str+=sql_after;
    }
    sql_str+=sql_finally;
    sql.prepare(sql_str);
    int pos=0;
    //绑定字段
    for(const auto&row:*mesinfo)
    {
        sql.bindValue(pos++,row.userid);
        sql.bindValue(pos++,row.userseq);
        sql.bindValue(pos++,row.syncseq);
        sql.bindValue(pos++,row.bindid);
        sql.bindValue(pos++,row.type);
        sql.bindValue(pos++,row.status);
        sql.bindValue(pos++,row.payload);
        sql.bindValue(pos++,row.sendtime);
    }
    sql.exec();
    //获取用户id
    qint64 userid=mesinfo->begin()->userid;
    //更新通知连续序列
    hasnextnoticeseq(userid);
}

//判断下一个会话序列游标是否连续
void DBManager::hasnextconvseq(const qint64 userid,const qint64 convid)
{
    bool next=false;
    QSqlQuery sql(db);
    //先取出最大连续游标
    auto it=convinfohash.find(convid);
    //新加的好友还没有会话信息插入会话信息
    if(it==convinfohash.end())
    {
        sql.prepare("insert into convseqtable(seqowern,convid,lastconvseq) values(?,?,0) ON CONFLICT(seqowern,convid) DO NOTHING");
        sql.bindValue(0,userid);
        sql.bindValue(1,convid);
        sql.exec();
        //将会话信息插入哈希表
        convinfohash.emplace(convid,0);
    }
    qint64 lastconvseq=convinfohash.find(convid).value().convseq;
    //获取所有序列大于该会话最大连续游标的信息
    sql.prepare("select convseq from messagetable where convid=? AND convseq>? ORDER BY convseq");
    sql.bindValue(0,convid);
    sql.bindValue(1,lastconvseq);
    sql.exec();
    //连续判断下一个游标是否存在存在则不断推进然后更新
    while(sql.next())
    {
        //游标+1推进
        if(++lastconvseq==sql.value("convseq").toLongLong())
        {
            convinfohash.find(convid).value().convseq=lastconvseq;
        }
        //下一位游标不存在退出(出现空洞)
        else
        {
            break;
        }
        //推进成功代表下一条存在
        next=true;
    }
    //有成功推进游标进行更新(用实际连续游标 不用lastconvseq lastconvseq遇到空洞会多1)
    if(next)
    {
        sql.prepare("update convseqtable set lastconvseq=? where seqowern=? AND convid=?");
        sql.bindValue(0,convinfohash.find(convid).value().convseq);
        sql.bindValue(1,userid);
        sql.bindValue(2,convid);
        sql.exec();
    }
}
//判断用户通知序列是否连续
void DBManager::hasnextnoticeseq(const qint64 userid)
{
    bool next=false;
    QSqlQuery sql(db);
    //推进用户通知序列
    next=hasnextuserseq(userid);
    //推进用户同步序列(用户序列推进成功保留true)
    if(!next) next=hasnextsyncseq(userid);
    else hasnextsyncseq(userid);
    //有成功推进游标进行更新
    if(next)
    {
        sql.prepare("update noticeseqtable set lastnoticeseq=?,lastsyncseq=? where userid=?");
        sql.bindValue(0,noticeif.noticeseq.noticeseq);
        sql.bindValue(1,noticeif.noticeseq.syncseq);
        sql.bindValue(2,userid);
        sql.exec();
    }
}
//推进用户通知序列
bool DBManager::hasnextuserseq(const qint64 userid)
{
    bool next=false;
    QSqlQuery sql(db);
    //先取出最大连续游标
    qint64 lastnoticeseq=noticeif.noticeseq.noticeseq;
    //取出所有大于这个游标的数据(正序)
    sql.prepare("select userseq from noticetable where userid=? AND userseq>? ORDER BY userseq");
    sql.bindValue(0,userid);
    sql.bindValue(1,lastnoticeseq);
    sql.exec();
    //连续判断下一个通知游标是否存在存在则不断推进然后更新
    while(sql.next())
    {
        if(++lastnoticeseq==sql.value("userseq").toLongLong())
        {
            //更新内存连续游标
            noticeif.noticeseq.noticeseq=lastnoticeseq;
            //推进成功代表下一条存在
            next=true;
        }
        //出现空洞退出
        else
        {
            break;
        }
    }
    return next;
}
//推进用户同步序列
bool DBManager::hasnextsyncseq(const qint64 userid)
{
    bool next=false;
    QSqlQuery sql(db);
    qint64 lastsyncseq=noticeif.noticeseq.syncseq;
    //取出所有大于这个游标的数据(正序)
    sql.prepare("select syncseq from noticetable where userid=? AND syncseq>? ORDER BY syncseq");
    sql.bindValue(0,userid);
    sql.bindValue(1,lastsyncseq);
    sql.exec();

    //连续判断下一个同步游标是否存在存在则不断推进然后更新
    while(sql.next())
    {
        if(++lastsyncseq==sql.value("syncseq").toLongLong())
        {
            //更新内存连续游标
            noticeif.noticeseq.syncseq=lastsyncseq;
            //推进成功代表下一条存在
            next=true;
        }
        //出现空洞退出
        else
        {
            break;
        }
    }
    return next;
}
//获取用户好友通知信息
void DBManager::getNewFriendNotice(const qint64 userid)
{
    QSqlQuery sql(db);
    std::shared_ptr<QList<DisplayNoticeInfo>> ldpni=std::make_shared<QList<DisplayNoticeInfo>>();
    qint64 noticelwbdseq=noticeif.noticelwbdseq;
    qint64 noticeupbdseq=noticeif.noticeupbdseq;
    QString sql_str=noticeupbdseq==-1?
                          //上界为-1说明为第一次打开好友通知界面获取前20条通知
                          "select userid,userseq,bindid,status,payload,sendtime from noticetable where userid=? AND type=? ORDER BY userseq LIMIT 20":
                          //反之获取期间的所有新通知(所有大于上界序列的数据)
                          "select userid,userseq,bindid,status,payload,sendtime from noticetable where userid=? AND type=? AND userseq>? ORDER BY userseq";
    sql.prepare(sql_str);
    sql.bindValue(0,userid);
    sql.bindValue(1,1);
    if(noticeupbdseq!=-1)
    {sql.bindValue(2,noticeupbdseq);}
    sql.exec();

    //获取通知数据
    while(sql.next())
    {
        qint64 userid=sql.value("userid").toLongLong();
        qint64 bindid=sql.value("bindid").toLongLong();
        qint8 status=sql.value("status").toInt();
        QString payload=sql.value("payload").toString();
        qint64 sendtime=sql.value("sendtime").toLongLong();
        ldpni->emplace_back(payload,userid,bindid,sendtime,status);
        //更新上界序列
        if(noticeupbdseq<sql.value("userseq").toLongLong())
            noticeupbdseq=sql.value("userseq").toLongLong();
        //更新下界序列
        if(noticelwbdseq>sql.value("userseq").toLongLong()&&noticelwbdseq!=-1)
            noticelwbdseq=sql.value("userseq").toLongLong();
        //第一条通知上界和下界一样
        else
            noticelwbdseq=sql.value("userseq").toLongLong();
    }
    noticeif.noticelwbdseq=noticelwbdseq;
    noticeif.noticeupbdseq=noticeupbdseq;
    emit return_FRIENDNOTICE_Display(ldpni);
}
//好友通知拉旧
void DBManager::getOlderFriendNotice(const qint64 userid)
{
    //下界小于等于1表示到底了
    if(noticeif.noticelwbdseq<=1)
        return;
    //获取后20条消息
    QSqlQuery sql(db);
    std::shared_ptr<QList<DisplayNoticeInfo>>ldpni=std::make_shared<QList<DisplayNoticeInfo>>();
    QString sql_str="select userid,userseq,bindid,status,payload,sendtime from noticetable where userid=? AND type=? AND userseq<? ORDER BY userseq DESC LIMIT 20";
    sql.bindValue(0,userid);
    sql.bindValue(1,1);
    sql.bindValue(2,noticeif.noticelwbdseq);
    sql.exec();
    while(sql.next())
    {
        qint64 userid=sql.value("useid").toLongLong();
        qint64 userseq=sql.value("userseq").toLongLong();
        qint64 bindid=sql.value("bindid").toLongLong();
        qint8 status=sql.value("status").toInt();
        QString payload=sql.value("payload").toString();
        qint64 sendtime=sql.value("sendtime").toLongLong();
        //更新下界序列
        if(noticeif.noticelwbdseq>userseq)
            noticeif.noticelwbdseq=userseq;
        ldpni->emplace_back(payload,userid,bindid,sendtime,status);
    }
    //传数据给处理层
    emit return_FRIENDNOTICE_Display(ldpni);
}
//聊天记录拉新
void DBManager::getChatHistory_New(const qint64 convid)
{
    //没有此会话
    if(!convinfohash.contains(convid))
        return;
    ConvInfo&convinfo=convinfohash.find(convid).value();
    QSqlQuery sql(db);
    std::shared_ptr< QList<Mes>> ldpni=std::make_shared<QList<Mes>>();
    QString sql_str=convinfo.curupbdseq==-1?
                          //上界为-1说明为第一次打开聊天窗口界面获取前20条通知
                          "select convid,convseq,sendid,content,sendtime from messagetable where convid=? ORDER BY convseq DESC LIMIT 20":
                          //反之焦点回转获取期间的所有新消息(所有大于上界序列的数据)
                          "select convid,convseq,sendid,content,sendtime from messagetable where convid=? AND convseq>? ORDER BY convseq DESC";
    sql.prepare(sql_str);
    sql.bindValue(0,convid);
    if(convinfo.curupbdseq!=-1)
    {sql.bindValue(1,convinfo.curupbdseq);}
    sql.exec();

    //获取消息数据
    while(sql.next())
    {
        qint64 convid=sql.value("convid").toLongLong();
        qint64 convseq=sql.value("convseq").toLongLong();
        //发送中或失败的消息序列为-1 不加入返回列表
        if(convseq==-1)
            continue;
        qint8 sendid=sql.value("sendid").toInt();
        QString content=sql.value("content").toString();
        qint64 sendtime=sql.value("sendtime").toLongLong();
        ldpni->emplaceFront(content,sendtime,convid,convseq,sendid);
        //更新上界序列
        if(convinfo.curupbdseq<convseq)
            convinfo.curupbdseq=sql.value("convseq").toLongLong();
        //更新下界序列
        if(convinfo.convlwbdseq>convseq&&convinfo.convlwbdseq!=-1)
            convinfo.convlwbdseq=sql.value("convseq").toLongLong();
        //第一条通消息上界和下界一样
        else
            convinfo.convlwbdseq=convseq;
    }
    emit return_CONVMES_Display(ldpni);
}
//聊天记录拉旧
void DBManager::getChatHistory_Older(const qint64 convid)
{
    std::shared_ptr<QList<Mes>>ldpni=std::make_shared<QList<Mes>>();
    //没有此会话 或 到底了：无条件发空列表，让 UI 复位拉旧中标志
    if(!convinfohash.contains(convid) || convinfohash.find(convid).value().convlwbdseq<=1)
    {
        emit return_CONVMES_Display(ldpni);
        return;
    }
    ConvInfo&convinfo=convinfohash.find(convid).value();
    //获取后20条消息
    QSqlQuery sql(db);
    QString sql_str="select convid,convseq,sendid,content,sendtime from messagetable where convid=? AND convseq<? ORDER BY convseq DESC LIMIT 20";
    sql.prepare(sql_str);
    sql.bindValue(0,convid);
    sql.bindValue(1,convinfo.convlwbdseq);
    sql.exec();
    while(sql.next())
    {
        qint64 convid=sql.value("convid").toLongLong();
        qint64 convseq=sql.value("convseq").toLongLong();
        //发送中或失败的消息序列为-1 不加入返回列表
        if(convseq==-1)
        {
            continue;
        }
        qint8 sendid=sql.value("sendid").toInt();
        QString content=sql.value("content").toString();
        qint64 sendtime=sql.value("sendtime").toLongLong();
        Mes m;
        m.content=content;
        m.sendtime=sendtime;
        m.convid=convid;
        m.convseq=convseq;
        m.sendid=sendid;
        m.isolder=true; // 标记为拉旧的历史消息
        ldpni->emplace_back(m);
        //更新下界序列
        if(convinfo.convlwbdseq>convseq)
            convinfo.convlwbdseq=convseq;
    }
    //传数据给
    emit return_CONVMES_Display(ldpni);
}
//重置聊天窗口上下界
void DBManager::resetChatBounds(const qint64 convid)
{
    if(convinfohash.contains(convid))
    {
        auto it=convinfohash.find(convid);
        it->convlwbdseq=-1;
        it->curupbdseq=-1;
    }
}
//查询所有发送中的消息
void DBManager::getSendingMessages()
{
    QSqlQuery sql(db);
    std::shared_ptr<QList<Mes>>sendingmes=std::make_shared<QList<Mes>>();
    //只查status=发送中 走status索引 不全表扫
    sql.prepare("select convid,convseq,sendid,content,sendtime,uuid,status from messagetable where status=?");
    sql.bindValue(0,static_cast<qint8>(MsgStatus::Sending));
    sql.exec();
    while(sql.next())
    {
        Mes m;
        m.convid=sql.value("convid").toLongLong();
        m.convseq=sql.value("convseq").toLongLong();
        m.sendid=sql.value("sendid").toLongLong();
        m.content=sql.value("content").toString();
        m.sendtime=sql.value("sendtime").toLongLong();
        m.uuid=sql.value("uuid").toString();
        m.status=sql.value("status").toInt();
        sendingmes->emplace_back(m);
    }
    emit returnSendingMes(sendingmes);
}

//初始化数据库
void DBManager::DBInit()
{
    //获取sqlite实例
    db=QSqlDatabase::addDatabase("QSQLITE",USERDB);
    //连接库名
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/user_sqlite.db");
    if(!db.open())
    {
        lg()(LogFatal,LogSCREEN,QString("数据库打开失败:%1").arg(db.lastError().text()));
        exit(2);
    }
    QSqlQuery sql(db);
    //登入信息
    if(!sql.exec(R"(create table if not exists logintable(
                useraccount   TEXT     NOT NULL UNIQUE ,
                userpassword  TEXT     NOT NULL        ,
                auto_login    INTEGER  NOT NULL        ,
                rememberpwd   INTEGER  NOT NULL        ,
                lastlogintime BIGINT   NOT NULL DEFAULT CURRENT_TIMESTAMP
                );
                )"))
    {
        lg()(LogError,LogSCREEN,"表logintable创建失败:"+sql.lastError().text());
        exit(2);
    }
    if(!sql.exec("create INDEX IF NOT EXISTS idx_lasttime ON logintable(lastlogintime);"))
    {
        lg()(LogError,LogSCREEN,"表logintable索引创建失败:"+sql.lastError().text());
        exit(2);
    }
    //消息表
    if(!sql.exec(R"(create table if not exists messagetable(
                convid   INTEGER  NOT NULL       ,
                convseq  INTEGER  NOT NULL       ,
                sendid   INTEGER  NOT NULL       ,
                content  TEXT     NOT NULL       ,
                sendtime INTEGER  NOT NULL       ,
                uuid     TEXT     NOT NULL       ,
                status   INTEGER  NOT NULL
                );)"))
    {
        lg()(LogError,LogSCREEN,"表messagetable创建失败:"+sql.lastError().text());
        exit(2);
    }
    //会话序列唯一索引
    if(!sql.exec("create INDEX IF NOT EXISTS idx_conv ON messagetable(convid,convseq);"))
    {
        lg()(LogError,LogSCREEN,"表messagetable索引创建失败:"+sql.lastError().text());
        exit(2);
    }
    //uuid唯一索引（upsert匹配发送中用）
    if(!sql.exec("create UNIQUE INDEX IF NOT EXISTS idx_uuid ON messagetable(uuid);"))
    {
        lg()(LogError,LogSCREEN,"表messagetable uuid索引创建失败:"+sql.lastError().text());
        exit(2);
    }
    //status索引（查询发送中消息用）
    if(!sql.exec("create INDEX IF NOT EXISTS idx_status ON messagetable(status);"))
    {
        lg()(LogError,LogSCREEN,"表messagetable status索引创建失败:"+sql.lastError().text());
        exit(2);
    }
    //通知表
    if(!sql.exec(R"(create table if not exists noticetable(
                userid   INTEGER NOT NULL ,
                userseq  INTEGER NOT NULL ,
                syncseq  INTEGER NOT NULL DEFAULT 0 ,
                bindid   INTEGER NOT NULL ,
                type     INTEGER NOT NULL ,
                status   INTEGER NOT NULL ,
                payload  TEXT    NOT NULL ,
                sendtime INTEGER NOT NULL
                );)"))
    {
        lg()(LogError,LogSCREEN,"表noticetable创建失败:"+sql.lastError().text());
        exit(2);
    }
    if(!sql.exec("create INDEX IF NOT EXISTS uid_idx ON noticetable(userid,type,userseq);"))
    {
        lg()(LogError,LogSCREEN,"表noticetable索引创建失败:"+sql.lastError().text());
        exit(2);
    }
    if(!sql.exec("create UNIQUE INDEX IF NOT EXISTS uid_bid_uni ON noticetable(userid,bindid);"))
    {
        lg()(LogError,LogSCREEN,"表noticetable唯一索引创建失败:"+sql.lastError().text());
        exit(2);
    }
    //通知序列表
    if(!sql.exec(R"(create table if not exists noticeseqtable(
                userid        INTEGER NOT NULL UNIQUE ,
                lastnoticeseq INTEGER NOT NULL DEFAULT 0,
                lastsyncseq   INTEGER NOT NULL DEFAULT 0
                );)"))
    {
        lg()(LogError,LogSCREEN,"表noticeseqtable创建失败:"+sql.lastError().text());
        exit(0);
    }
    if(!sql.exec("create INDEX IF NOT EXISTS userid_idx ON noticeseqtable(userid);"))
    {
        lg()(LogError,LogSCREEN,"表noticeseqtable索引创建失败:"+sql.lastError().text());
        exit(2);
    }
    //会话序列表
    if(!sql.exec(R"(create table if not exists convseqtable(
                seqowern    INTEGER NOT NULL ,
                convid      INTEGER NOT NULL ,
                lastconvseq INTEGER NOT NULL DEFAULT 0
                );)"))
    {
        lg()(LogError,LogSCREEN,"表convseqtable创建失败:"+sql.lastError().text());
        exit(0);
    }
    if(!sql.exec("create UNIQUE INDEX IF NOT EXISTS convid_idx ON convseqtable(seqowern,convid);"))
    {
        lg()(LogError,LogSCREEN,"表noticeseqtable索引创建失败:"+sql.lastError().text());
        exit(2);
    }
}
//关闭数据库
void DBManager::DBClose()
{
    //关闭数据库
    //判断数据库是否打开和初始化成功
    if(db.isOpen()&&db.isValid())
    {
        db.close();
        QString dbname=db.connectionName();
        //清除句柄
        db=QSqlDatabase();
        QSqlDatabase::removeDatabase(dbname);
    }
}
