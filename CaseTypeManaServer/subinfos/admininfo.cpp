#include "admininfo.h"

#include <QDebug>

AdminInfo::AdminInfo()
{
    m_id.clear();
    m_name.clear();
    m_sex.clear();
    m_age.clear();
    m_phone.clear();
}

AdminInfo::AdminInfo(const QString &id, const QString &name,
                          const QString &sex, const QString &age, const QString &phone)
{
    m_id = id;
    m_name = name;
    m_sex = sex;
    m_age = age;
    m_phone = phone;
}

void AdminInfo::display()const
{
    qDebug() << "ID:" << m_id;
    qDebug() << "Name:" << m_name;
    qDebug() << "Sex:" << m_sex;
    qDebug() << "Age:" << m_age;
    qDebug() << "Phone:" << m_phone;
}

void AdminInfo::setID(const QString &id)
{
    m_id = id;
}
void AdminInfo::setName(const QString &name)
{
    m_name = name;
}

void AdminInfo::setSex(const QString &sex)
{
    m_sex = sex;
}

void AdminInfo::setAge(const QString &age)
{
    m_age = age;
}

void AdminInfo::setPhone(const QString &phone)
{
    m_phone = phone;
}

const QString &AdminInfo::getID()const
{
    return m_id;
}
const QString &AdminInfo::getName()const
{
    return m_name;
}

const QString &AdminInfo::getSex()const
{
    return m_sex;
}

const QString &AdminInfo::getAge() const
{
    return m_age;
}

const QString &AdminInfo::getPhone()const
{
    return m_phone;
}
