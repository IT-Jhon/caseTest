#ifndef MSGSOCKET_H
#define MSGSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QMap>

#include <QString>

class MsgSocket : public QObject
{
    Q_OBJECT

signals:
//    void signalRegisterSocket(QString id, MsgSocket *socket);
    void signalLogoutSocket(QString id, MsgSocket *socket);

public slots:
    void slotReadyRead();
    bool slotSendMsg(QString msg);

public:
    explicit MsgSocket(QTcpSocket *socket, QObject *parent = 0);
    ~MsgSocket();

    QString m_localUid;

private:
    quint16 m_tcpBlockSize;
    QTcpSocket *m_socket;

    void parseUserAsk(QString msg);
    ///通用请求命令 - 登录退出在MsgSocket中实现
    void parseUserLogin(QString data);
    void parseUserInfo(QString data);
//    void parseChangePswd(QString data);
    void parseUserExit(QString data);
    void parseSearchCaseInfoIf(const QString &cond_data, const QString &cond_value);
    void parseSearchCaseInfo(QString data);
    void parseCaseLimitTimeInfo(QString data);
    void parseModCaseLitTime(QString data);
    void parseDelCaseInfo(QString data);

    void sleep(unsigned int msec);  //msec为毫秒
};

#endif // MSGSOCKET_H
