#ifndef GLOBALVARS_H
#define GLOBALVARS_H

#include <QQueue>
//#include <QSet>

#include "userinfo.h"
#include "admininfo.h"
#include "caseinfo.h"
#include "timelimitinfo.h"

#define USE_DATABASE 1

enum Oper_Data{
    Oper_None,
    Oper_Add,
    Oper_Del,
    Oper_Mdy
};

enum RESPONSE{
    RES_Down = '!',
    RES_Fail = '?'
};

enum COMMAND{
    ///通用请求命令
    CMD_UserLogin_L = 'L',          //用户登录
    CMD_UserInfo_I = 'I',           //获取个人信息
    CMD_ChangePswd_H = 'H',         //修改密码
    CMD_UserExit_X = 'X',           //用户退出
    CMD_SearchCaseInfo_S = 'S',     //案件查询
    CMD_LimitTimeInfo_T = 'T' ,      //受理时限获取
    CMD_ModLimitTimeInfo_M = 'M',    //修改受理时限
    CMD_DelCaseInfo_D = 'D'         //删除案件信息
};

class GlobalVars
{
public:
    static QQueue<QString> g_msgQueue; //消息队列

    static UserInfoMap g_userInfoMap;
    static AdminInfoMap g_adminInfoMap;
    static CaseInfoMap g_caseInfoMap;
    static TimeLimitInfoMap g_timeLimitInfoMap;


    static UserInfoList *g_userInfoList;
    static AdminInfoList *g_adminInfoList;
    static CaseInfoList *g_caseInfoList;
    static TimeLimitInfoList *g_timeLimitInfoList;

    static int g_searchCaseInfoLen;
};

#endif // GLOBALVARS_H
