#include "timelimitinfo.h"

#include <QDebug>

TimeLimitInfo::TimeLimitInfo()
{
   m_adminID.clear();
   m_caseID.clear();
   m_limitTime.clear();
}

TimeLimitInfo::TimeLimitInfo(const QString &adminID, const QString &caseID,
                             const QString &limitTime)
{
    m_adminID = adminID;
    m_caseID = caseID;
    m_limitTime = limitTime;
}

void TimeLimitInfo::display() const
{
    qDebug() << "AdminID" << m_adminID;
    qDebug() << "CaseID" << m_caseID;
    qDebug() << "LimitTimeID" << m_limitTime;
}

void TimeLimitInfo::setAdminID(const QString &adminID)
{
    m_adminID = adminID;
}

void TimeLimitInfo::setCaseID(const QString &caseID)
{
    m_caseID = caseID;
}

void TimeLimitInfo::setLimitTime(const QString &limitTime)
{
    m_limitTime = limitTime;
}

const QString &TimeLimitInfo::getAdminID() const
{
    return m_adminID;
}

const QString &TimeLimitInfo::getCaseID() const
{
    return m_caseID;
}

const QString &TimeLimitInfo::getLimitTime() const
{
    return m_limitTime;
}

