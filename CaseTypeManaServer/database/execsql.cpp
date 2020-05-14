#include "execsql.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>

#include <QDebug>

///////////////////////UserInfo////////////////////////////
void ExecSQL::searchAllUserInfos()
{
    QString queryString = QString("select * from user_info");
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::searchUserInfoForID(const QString &value)
{
    QString queryString = QString("select * from user_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::searchUserInfoForRole(const QString &value)
{
    QString queryString = QString("select * from user_info where role = '%1'").arg(value);
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::searchUserInfoForDate(const QString &value)
{
    QString queryString = QString("select * from user_info where date = '%1'").arg(value);
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::updateUserInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_userInfoList->clear();
    GlobalVars::g_userInfoMap.clear();

    if(query.exec(sql))
    {
         int id_idx = query.record().indexOf("id");
         int pswd_idx = query.record().indexOf("pswd");
         int role_idx = query.record().indexOf("role");
         int date_idx = query.record().indexOf("date");

         while(query.next())
         {
            QString id = query.value(id_idx).toString();
            QString pswd = query.value(pswd_idx).toString();
            QString role = query.value(role_idx).toString();
            QString date = query.value(date_idx).toString();

            UserInfo info(id, pswd, role, date);
            GlobalVars::g_userInfoList->append(info);
         }

         for(UserInfoList::iterator it = GlobalVars::g_userInfoList->begin();
             it != GlobalVars::g_userInfoList->end(); it++)
         {
            GlobalVars::g_userInfoMap.insert(it->getID(), it);
         }
    }
}

bool ExecSQL::addNewUserInfo(const UserInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into user_info values('%1', '%2', '%3', %4)")
            .arg(info.getID()).arg(info.getPswd()).arg(info.getRole()).arg(info.getRole());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeUserInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from user_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyUserInfoForPswd(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update user_info set pswd = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyUserInfoForRole(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update user_info set role = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyUserInfoForDate(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update user_info set date = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

///////////////////////AdminInfo/////////////////////////////

void ExecSQL::searchAllAdminInfos()
{
    QString queryString = QString("select * from admin_info");
    qDebug() << queryString;

    updateAdminInfoList(queryString);
}

void ExecSQL::searchAdminInfoForID(const QString &value)
{
    QString queryString = QString("select * from admin_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateAdminInfoList(queryString);
}

void ExecSQL::searchAdminInfoForName(const QString &value)
{
    QString queryString = QString("select * from admin_info where name = '%1'").arg(value);
    qDebug() << queryString;

    updateAdminInfoList(queryString);
}

void ExecSQL::updateAdminInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_adminInfoList->clear();
    if(query.exec(sql))
    {
        int id_idx = query.record().indexOf("id");
        int name_idx = query.record().indexOf("name");
        int sex_idx = query.record().indexOf("sex");
        int age_idx = query.record().indexOf("age");
        int phone_idx = query.record().indexOf("phone");

        while (query.next())
        {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx).toString();
            QString sex = query.value(sex_idx).toString();
            QString age = query.value(age_idx).toString();
            QString phone = query.value(phone_idx).toString();

            AdminInfo info(id, name, sex, age, phone);
            info.display();
            GlobalVars::g_adminInfoList->append(info);
        }

        for (AdminInfoList::iterator it = GlobalVars::g_adminInfoList->begin();
             it != GlobalVars::g_adminInfoList->end(); it++)
        {
            GlobalVars::g_adminInfoMap.insert(it->getID(), it);
        }
    }
}

bool ExecSQL::addNewAdminInfo(const AdminInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into admin_info values('%1', '%2', '%3', '%4', '%5')")
            .arg(info.getID()).arg(info.getName()).arg(info.getSex()).arg(info.getAge()).arg(info.getPhone());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeAdminInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from student_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyAdminInfoForName(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update admin_info set name = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyAdminInfoForSex(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update admin_info set sex = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyAdminInfoForAge(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update admin_info set age = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyAdminInfoForPhone(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update admin_info set phone = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

///////////////////////CaseInfo////////////////////////////////////////////////////////
void ExecSQL::searchAllCaseInfos()
{
    QString queryString = QString("select * from falltypus_info");
    qDebug() << queryString;

    updateCaseInfoList(queryString);
}

void ExecSQL::searchCaseInfoForID(const QString &value)
{
    QString queryString = QString("select * from falltypus_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateCaseInfoList(queryString);
}

void ExecSQL::searchCaseInfoForType(const QString &value)
{
    QString queryString = QString("select * from falltypus_info where falltypus = '%1'").arg(value);
    qDebug() << queryString;

    updateCaseInfoList(queryString);
}

void ExecSQL::searchCaseInfoForName(const QString &value)
{
    QString queryString = QString("select * from falltypus_info where name = '%1'").arg(value);
    qDebug() << queryString;

    updateCaseInfoList(queryString);
}

void ExecSQL::updateCaseInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_caseInfoList->clear();
    if(query.exec(sql))
    {
        int id_idx = query.record().indexOf("id");
        int type_idx = query.record().indexOf("falltypus");
        int name_idx = query.record().indexOf("name");
        int condit_idx = query.record().indexOf("condit_case");

        while (query.next())
        {
            QString id = query.value(id_idx).toString();
            QString type = query.value(type_idx).toString();
            QString name = query.value(name_idx).toString();
            QString condit = query.value(condit_idx).toString();

            CaseInfo info(id, type, name, condit);
//            info.display();
            GlobalVars::g_caseInfoList->append(info);
        }

        for (CaseInfoList::iterator it = GlobalVars::g_caseInfoList->begin();
             it != GlobalVars::g_caseInfoList->end(); it++)
        {
            GlobalVars::g_caseInfoMap.insert(it->getID(), it);
        }
    }
}

bool ExecSQL::addNewCaseInfo(const CaseInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into falltypus_info values('%1', '%2', '%3', '%4')")
            .arg(info.getID()).arg(info.getCaseType()).arg(info.getName()).arg(info.getCaseCondit());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeCaseInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from falltypus_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyCaseInfoForType(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update falltypus_info set falltypus = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyCaseInfoForName(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update falltypus_info set name = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyCaseInfoForCondit(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update falltypus_info set condit_case = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

/////////////////////TimeLimitInfo////////////////////////////////////////////////
void ExecSQL::searchAllTimeLimitInfos()
{
    QString queryString = QString("select * from caseTmie_info");
    qDebug() << queryString;

    updateTimeLimitInfoList(queryString);
}

void ExecSQL::searchTimeLimitInfoForAdminID(const QString &value)
{
    QString queryString = QString("select * from caseTmie_info where admin_id = '%1'").arg(value);
    qDebug() << queryString;

    updateTimeLimitInfoList(queryString);
}

void ExecSQL::searchTimeLimitInfoForCaseID(const QString &value)
{
    QString queryString = QString("select * from caseTmie_info where case_id = '%1'").arg(value);
    qDebug() << queryString;

    updateTimeLimitInfoList(queryString);
}

void ExecSQL::updateTimeLimitInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_timeLimitInfoList->clear();
    if(query.exec(sql))
    {
        int adminID_idx = query.record().indexOf("admin_id");
        int caseID_idx = query.record().indexOf("case_id");
        int limitTime_idx = query.record().indexOf("limit_time");

        while (query.next())
        {
            QString adminID = query.value(adminID_idx).toString();
            QString caseID = query.value(caseID_idx).toString();
            QString limitTime = query.value(limitTime_idx).toString();

            TimeLimitInfo info(adminID, caseID, limitTime);
//            info.display();
            GlobalVars::g_timeLimitInfoList->append(info);
        }

        for (TimeLimitInfoList::iterator it = GlobalVars::g_timeLimitInfoList->begin();
             it != GlobalVars::g_timeLimitInfoList->end(); it++)
        {
            GlobalVars::g_timeLimitInfoMap.insert(it->getCaseID(), it);
        }
    }
}

bool ExecSQL::addNewTimeLimitInfo(const TimeLimitInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into caseTmie_info values('%1', '%2', '%3')")
            .arg(info.getAdminID()).arg(info.getCaseID()).arg(info.getLimitTime());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeTimeLimitInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from caseTmie_info where case_id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyTimeLimitInfoForLimitTime(const QString &caseID, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update caseTmie_info set limit_time = '%1' where case_id = '%2'").arg(value).arg(caseID);
    qDebug() << queryString;
    return query.exec(queryString);
}
