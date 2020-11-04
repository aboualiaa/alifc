//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_PC_GUI_H
#define ALIFC_PC_GUI_H
#include <string>

void cpp_AddScript(const std::string &FUN, const std::string &NEW_CODE);
std::string CG_WINX_LOAD();
std::string CG_APP_DESTROY();
std::string CG_WIN_SHOW(const std::string &WIN);
std::string CG_WIN_CENTER(const std::string &WIN);
std::string CG_WIN_HIDE(const std::string &WIN);
std::string CG_WIN_DESTROY(const std::string &WIN);
std::string CG_WIN_MEMBER(const std::string &WIN,
                          const std::string &MEMBER_CODE);
std::string AlifJavaScript_Bridge_SendRequest();
std::string
AlifJavaScript_Bridge_OnNewWindowSendRequest(const std::string &WVObjName);
std::string Generate_AlifJavaScript();
void CG_INITIALIZATION();
std::string CG_WINX_CODE();
std::string CODE_GENERATOR_GET_PC_GUI();

extern std::string AlifJavaScript_Bridge;

#endif // ALIFC_PC_GUI_H
