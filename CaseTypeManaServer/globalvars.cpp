#include "globalvars.h"

QQueue<QString> GlobalVars::g_msgQueue;

UserInfoMap GlobalVars::g_userInfoMap;
AdminInfoMap GlobalVars::g_adminInfoMap;
CaseInfoMap GlobalVars::g_caseInfoMap;
TimeLimitInfoMap GlobalVars::g_timeLimitInfoMap;

UserInfoList *GlobalVars::g_userInfoList = new UserInfoList;
AdminInfoList *GlobalVars::g_adminInfoList = new AdminInfoList;
CaseInfoList *GlobalVars::g_caseInfoList = new CaseInfoList;
TimeLimitInfoList *GlobalVars::g_timeLimitInfoList = new TimeLimitInfoList;

int GlobalVars::g_searchCaseInfoLen = 0;
