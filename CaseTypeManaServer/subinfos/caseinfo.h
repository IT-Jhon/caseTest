#ifndef CASEINFO_H
#define CASEINFO_H

#include <QString>
#include <QList>
#include <QMap>

class CaseInfo
{
public:
    CaseInfo();
    CaseInfo(const QString &id, const QString &caseType,
             const QString &name, const QString & caseCondit);

    void display()const;

    void setID(const QString &id);
    void setCaseType(const QString &caseType);
    void setName(const QString &name);
    void setCaseCondit(const QString &condit);

    const QString &getID()const;
    const QString &getCaseType()const;
    const QString &getName()const;
    const QString &getCaseCondit()const;

private:
    QString m_id;
    QString m_caseType;
    QString m_name;
    QString m_caseCondit;
};
typedef QList<CaseInfo> CaseInfoList;
typedef QMap<QString, CaseInfoList::iterator> CaseInfoMap;

#endif // CASEINFO_H
