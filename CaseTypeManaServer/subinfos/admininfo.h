#ifndef ADMININFO_H
#define ADMININFO_H

#include <QString>
#include <QList>
#include <QMap>

class AdminInfo
{
public:
    AdminInfo();
    AdminInfo(const QString &id, const QString &name,
              const QString &sex, const QString &age,
              const QString &phone);

    void display()const;

    void setID(const QString &id);
    void setName(const QString &name);
    void setSex(const QString &sex);
    void setAge(const QString &age);
    void setPhone(const QString &phone);

    const QString &getID()const;
    const QString &getName()const;
    const QString &getSex()const;
    const QString &getAge()const;
    const QString &getPhone()const;

private:
    QString m_id;
    QString m_name;
    QString m_sex;
    QString m_age;
    QString m_phone;
};

typedef QList<AdminInfo> AdminInfoList;
typedef QMap<QString, AdminInfoList::iterator> AdminInfoMap;

#endif // ADMININFO_H
