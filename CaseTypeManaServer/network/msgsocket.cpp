#include "msgsocket.h"
#include "globalvars.h"
#include "timelimitinfo.h"

#include <QStringBuilder>
#include <QTime>
#include <QCoreApplication>
#include "execsql.h"

MsgSocket::MsgSocket(QTcpSocket *socket, QObject *parent):
    QObject(parent)
{
    qDebug() << "MsgSocket::MsgSocket";
    m_tcpBlockSize = 0;

    m_socket = socket;
//    connect(m_socket, SIGNAL(disconnected()),
//            m_socket, SLOT(deleteLater()));
    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
}

MsgSocket::~MsgSocket()
{
    delete m_socket;
}

bool MsgSocket::slotSendMsg(QString msg)
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    out << (quint16)0;
    out << msg;
    out.device()->seek(0);
    out << (quint16)(buffer.size() - sizeof(quint16));

    qDebug() << "Server Send: " ;
    qDebug() << msg;

    return m_socket->write(buffer);
}

void MsgSocket::slotReadyRead()
{
    qDebug() << "MsgSocket::slotReadyRead()";
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_4_6);

    if(m_tcpBlockSize == 0)
    {
        if(m_socket->bytesAvailable()<sizeof(quint16))
            return;

        in >> m_tcpBlockSize;
//        qDebug() << "m_tcpBlockSize:" <<m_tcpBlockSize;
    }

    if(m_socket->bytesAvailable() < m_tcpBlockSize)
        return;

    QString msg;
    in >> msg;
    qDebug() << "Server Recv: " << msg;
    parseUserAsk(msg);

//    if(msg.at(0) == CMD_UserLogin_L)
//    {
//        parseUserLogin(msg);
//    }/*else if(msg.at(0) == CMD_UserExit_X)
//    {
//        parseUserExit(msg);
//    }*/else
//    {
//        GlobalVars::g_msgQueue.enqueue(msg);
//    }
    m_tcpBlockSize = 0;
}

///解析通用请求命令
void MsgSocket::parseUserAsk(QString msg)
{
    qDebug()<< "MsgSocket::parseUserAsk(QString msg)" << msg;
    QStringList list = msg.split("#");
    int cmd = msg.at(0).toLatin1();
    switch (cmd) {
    ///通用请求命令
    case CMD_UserLogin_L: parseUserLogin(list.at(1)); break;
    case CMD_UserInfo_I: parseUserInfo(list.at(1)); break;
//    case CMD_ChangePswd_H: parseChangePswd(list.at(1)); break;
    case CMD_UserExit_X: parseUserExit(list.at(1)); break;
    case CMD_SearchCaseInfo_S:parseSearchCaseInfo(list.at(1)); break;
    case CMD_LimitTimeInfo_T:parseCaseLimitTimeInfo(list.at(1)); break;
    case CMD_ModLimitTimeInfo_M:parseModCaseLitTime(list.at(1)); break;
    case CMD_DelCaseInfo_D:parseDelCaseInfo(list.at(1));    break;
    default:
        break;
    }
}

void MsgSocket::parseUserLogin(QString msg)
{
    qDebug() << "MsgSocket::parseUserLogin" << msg;

    QStringList list = msg.remove("L#").split("|");
    QString id = list.at(0);
    QString pswd = list.at(1);
    qDebug()<< "id" << id;
    qDebug()<< "pswd" << pswd;

    if(GlobalVars::g_userInfoMap.contains(id))
    {
        UserInfoList::iterator it = GlobalVars::g_userInfoMap[id];
        if(it->getPswd() == pswd)
        {
            QString msg = QString(CMD_UserLogin_L)
                    % QString("#!|") % it->getID()
                    % "|" % it->getPswd()
                    % "|" % it->getRole()
                    % "|" % it->getDate();
            this->slotSendMsg(msg);
        }else
        {
            QString msg = QString(CMD_UserLogin_L)
                    % QString("#?|") % QString("Error: UID Or Pswd!");
            this->slotSendMsg(msg);
        }
    }
}

void MsgSocket::parseUserInfo(QString data)
{
    qDebug() << "MsgSocket::parseUserInfo" << data;
    QStringList list = data.split("|");
    QString id = list.at(0);
    QString role = list.at(1);
    qDebug() << "id:" << id ;
    qDebug() << "role:" << role;
    if(role == "顾客")
    {

    }else if(role == "商家")
    {

    }else
    {
        QString msg = QString(CMD_UserInfo_I)
                % QString("#?|") % QString("Error: DataError");
        slotSendMsg(msg);
    }

}

//void MsgSocket::parseChangePswd(QString data)
//{
//    qDebug() << "parseChangePswd: " << data;
//    QStringList list = data.split("|");
//    QString id = list.at(0);
//    QString pswd = list.at(1);
//    if(ExecSql::modifyUserInfoForPswd(id, pswd))
//    {
//        QString msg = QString(CMD_ChangePswd_H)
//                % QString("#|!");
//        slotSendMsg(msg);
//    }else
//    {
//        QString msg = QString(CMD_ChangePswd_H)
//                % QString("#|?");
//        slotSendMsg(msg);
//    }

//}

void MsgSocket::parseUserExit(QString msg)
{
    qDebug() << "MsgSocket::parseUserExit" << msg;
    msg.remove("X#");

    emit signalLogoutSocket(msg, this);
    QString msg1 = QString(CMD_UserExit_X)
            % QString("#!|") % msg;
    if(this->slotSendMsg(msg1))
    {
        delete this;
    }
}

void MsgSocket::parseSearchCaseInfoIf(const QString &cond_data, const QString &cond_value)
{
    if (GlobalVars::g_searchCaseInfoLen < GlobalVars::g_caseInfoList->length())
    {
        int &l_index = GlobalVars::g_searchCaseInfoLen;
        qDebug()<<"GlobalVars::g_searchCaseInfoLen"<< l_index;
        int lenght = GlobalVars::g_caseInfoList->length();

        QString msg = QString(CMD_SearchCaseInfo_S)
                % "#!|" % QString("%1").arg(l_index)
                % "|" % GlobalVars::g_caseInfoList->at(l_index).getID()
                % "|" % GlobalVars::g_caseInfoList->at(l_index).getCaseType()
                % "|" % GlobalVars::g_caseInfoList->at(l_index).getName()
                % "|" % GlobalVars::g_caseInfoList->at(l_index).getCaseCondit()
                % "|" % cond_data
                % "|" % cond_value;
        if (l_index == 0)
        {
            msg = msg % "|" %QString("%1").arg(lenght);
            slotSendMsg(msg);
        }else
        {
            slotSendMsg(msg);
        }
        GlobalVars::g_searchCaseInfoLen++;
    }
}

void MsgSocket::parseSearchCaseInfo(QString data)
{
    qDebug()<< "MsgSocket::pasreSearchCaseInfo(QString data)" <<  data;
    QStringList list = data.split("|");
    QString con_data = list.at(0);
    QString con_value = list.at(1);

    if (con_data == "无条件")
    {
        ExecSQL::searchAllCaseInfos();
        parseSearchCaseInfoIf(con_data, con_value);
    }else if (con_data == "编号")
    {
        ExecSQL::searchCaseInfoForID(con_value);
        parseSearchCaseInfoIf(con_data, con_value);
    }else if(con_data == "案件类型")
    {
        ExecSQL::searchCaseInfoForType(con_value);
        parseSearchCaseInfoIf(con_data, con_value);
    }else if(con_data == "名称")
    {
        ExecSQL::searchCaseInfoForName(con_value);
        parseSearchCaseInfoIf(con_data, con_value);
    }

    qDebug() << "发送第" << GlobalVars::g_searchCaseInfoLen;

    if (GlobalVars::g_searchCaseInfoLen == GlobalVars::g_caseInfoList->length())
    {
         GlobalVars::g_searchCaseInfoLen = 0;
         sleep(1000);
         QString msg = QString(CMD_SearchCaseInfo_S)
                 % "#?|" % QString("案件接收完毕！");
         slotSendMsg(msg);
    }
}

void MsgSocket::parseCaseLimitTimeInfo(QString data)
{
    qDebug() << "MsgSocket::parseCaseLimitTimeInfo(QString data)" << data;
    QStringList list = QString(data).split("|");
    QString id = list.at(0);

    ExecSQL::searchAllTimeLimitInfos();
    if (GlobalVars::g_timeLimitInfoMap.contains(id))
    {
        TimeLimitInfoList::iterator it = GlobalVars::g_timeLimitInfoMap[id];

        QString msg =QString(CMD_LimitTimeInfo_T)
                % "#!|" % it->getAdminID()
                % "|" % it->getCaseID()
                % "|" % it->getLimitTime();
        slotSendMsg(msg);
    }else
    {
        QString msg = QString(CMD_LimitTimeInfo_T) % "#?|" % QString("ERROR:Caseid-Litime No Find!");
        slotSendMsg(msg);
    }
}

void MsgSocket::parseModCaseLitTime(QString data)
{
    qDebug() << "MsgSocket::parseModCaseLitTime(QString data)" <<data;

    QStringList list = QString(data).split("|");
    QString caseid = list.at(1);

    ExecSQL::searchTimeLimitInfoForCaseID(caseid);

    if(GlobalVars::g_timeLimitInfoMap.contains(caseid))
    {
        ExecSQL::modifyTimeLimitInfoForLimitTime(caseid, list.at(2));
        QString msg = QString(CMD_ModLimitTimeInfo_M)
                % "#!|" % QString("Success:limitTime modify success.");
        slotSendMsg(msg);
    }else
    {
        QString msg = QString(CMD_ModLimitTimeInfo_M)
                % "#!|" % QString("Success:limitTime add success.");
        slotSendMsg(msg);
        QString adminID = list.at(0);
        QString caseID = list.at(1);
        QString limitTime = list.at(2);

        TimeLimitInfo info(adminID, caseID, limitTime);

        ExecSQL::addNewTimeLimitInfo(info);

    }
}

void MsgSocket::parseDelCaseInfo(QString data)
{
    qDebug() << "MsgSocket::parseDelCaseInfo(QString data)" << data;
    QStringList list = QString(data).split("|");
    QString id = list.at(0);

    ExecSQL::removeTimeLimitInfo(id);
    ExecSQL::removeCaseInfo(id);

    QString msg = QString(CMD_DelCaseInfo_D)
            % "#!|" % QString("Success:CaseInfo delete success.");
    slotSendMsg(msg);
}

void MsgSocket::sleep(unsigned int msec)  //msec为毫秒
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
