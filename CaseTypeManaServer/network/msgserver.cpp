#include "msgserver.h"
#include "globalvars.h"


#include "execsql.h"
#include <QStringBuilder>
#include <QAbstractSocket>



MsgServer::MsgServer(QObject *parent) :
    QObject(parent)
{
    m_server = new QTcpServer(this);

    m_server->listen(QHostAddress::Any, 55555);

    connect(m_server, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection()));
}


MsgServer::~MsgServer()
{

}


void MsgServer::slotNewConnection()
{
    qDebug() << "MsgServer::slotNewConnection()";

    QTcpSocket *socket = m_server->nextPendingConnection();

    MsgSocket *msgSocket = new MsgSocket(socket);
    connect(socket, SIGNAL(disconnected()),                  //   长短连接问题，接收到断开为短链接。
            socket, SLOT(deleteLater()));

}
