#include "caseinfo.h"
#include <QDebug>

CaseInfo::CaseInfo()
{
    m_id.clear();
    m_caseType.clear();
    m_name.clear();
    m_caseCondit.clear();
}

CaseInfo::CaseInfo(const QString &id, const QString &caseType,
                   const QString &name, const QString &caseCondit)
{
    m_id = id;
    m_caseType = caseType;
    m_name = name;
    m_caseCondit = caseCondit;
}

void CaseInfo::display()const
{
    qDebug()<< "ID" << m_id;
    qDebug()<< "CaseType" << m_caseType;
    qDebug()<< "name" << m_name;
    qDebug()<< "CaseCondit" << m_caseCondit;
}

void CaseInfo::setID(const QString &id)
{
    m_id = id;
}

void CaseInfo::setCaseType(const QString &caseType)
{
    m_caseType = caseType;
}

void CaseInfo::setName(const QString &name)
{
    m_name = name;
}

void CaseInfo::setCaseCondit(const QString &condit)
{
    m_caseCondit = condit;
}

const QString &CaseInfo::getID() const
{
    return m_id;
}

const QString &CaseInfo::getCaseType() const
{
    return m_caseType;
}

const QString &CaseInfo::getName() const
{
    return m_name;
}

const QString &CaseInfo::getCaseCondit() const
{
    return m_caseCondit;
}
