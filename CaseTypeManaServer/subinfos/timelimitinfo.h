#ifndef TIMELIMITINFO_H
#define TIMELIMITINFO_H

#include <QString>
#include <QList>
#include <QMap>

class TimeLimitInfo
{
public:
    TimeLimitInfo();
    TimeLimitInfo(const QString &adminID, const QString &caseID, const QString &limitTime);

    void display()const;

    void setAdminID(const QString &adminID);
    void setCaseID(const QString &caseID);
    void setLimitTime(const QString &limitTime);

    const QString &getAdminID()const;
    const QString &getCaseID()const;
    const QString &getLimitTime()const;
private:
    QString m_adminID;
    QString m_caseID;
    QString m_limitTime;
};
typedef QList<TimeLimitInfo> TimeLimitInfoList;
typedef QMap<QString, TimeLimitInfoList::iterator> TimeLimitInfoMap;

#endif // TIMELIMITINFO_H
