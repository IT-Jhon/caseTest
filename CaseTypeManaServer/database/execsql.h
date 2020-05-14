#ifndef EXECSQL_H
#define EXECSQL_H

#include "globalvars.h"

class ExecSQL
{
public:
    ///////////////////////UserInfo////////////////////////////////
    static void searchAllUserInfos();
    static void searchUserInfoForID(const QString &value);
    static void searchUserInfoForRole(const QString &value);
    static void searchUserInfoForDate(const QString &value);
    static void updateUserInfoList(const QString &sql);

    static bool addNewUserInfo(const UserInfo &info);
    static bool removeUserInfo(QString value);
    static bool modifyUserInfoForPswd(const QString &id, const QString &value);
    static bool modifyUserInfoForRole(const QString &id, const QString &value);
    static bool modifyUserInfoForDate(const QString &id, const QString &value);

    ///////////////////////AdminInfo/////////////////////////////
    static void searchAllAdminInfos();
    static void searchAdminInfoForID(const QString &value);
    static void searchAdminInfoForName(const QString &value);
    static void updateAdminInfoList(const QString &sql);

    static bool addNewAdminInfo(const AdminInfo &info);
    static bool removeAdminInfo(QString value);
    static bool modifyAdminInfoForName(const QString &id, const QString &value);
    static bool modifyAdminInfoForSex(const QString &id, const QString &value);
    static bool modifyAdminInfoForAge(const QString &id, const QString &value);
    static bool modifyAdminInfoForPhone(const QString &id, const QString &value);
    ///////////////////////CaseInfo/////////////////////////////////////////
    static void searchAllCaseInfos();
    static void searchCaseInfoForID(const QString &value);
    static void searchCaseInfoForType(const QString &value);
    static void searchCaseInfoForName(const QString &value);
    static void updateCaseInfoList(const QString &sql);

    static bool addNewCaseInfo(const CaseInfo &info);
    static bool removeCaseInfo(QString value);
    static bool modifyCaseInfoForType(const QString &id, const QString &value);
    static bool modifyCaseInfoForName(const QString &id, const QString &value);
    static bool modifyCaseInfoForCondit(const QString &id, const QString &value);
   //////////////////////////TimeLimitInfo////////////////////////////////////////////////
    static void searchAllTimeLimitInfos();
    static void searchTimeLimitInfoForAdminID(const QString &value);
    static void searchTimeLimitInfoForCaseID(const QString &value);
    static void searchTimeLimitInfoForLimitTime(const QString &value);
    static void updateTimeLimitInfoList(const QString &sql);

    static bool addNewTimeLimitInfo(const TimeLimitInfo &info);
    static bool removeTimeLimitInfo(QString value);
    static bool modifyTimeLimitInfoForLimitTime(const QString &caseID, const QString &value);
};

#endif // EXECSQL_H
