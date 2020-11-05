//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef GENERATOR_PC_GUI_H
#define GENERATOR_PC_GUI_H
#include <string>

void cpp_AddScript(const std::string &FUN, const std::string &NEW_CODE);
auto CG_WINX_LOAD() -> std::string;
auto CG_APP_DESTROY() -> std::string;
auto CG_WIN_SHOW(const std::string &WIN) -> std::string;
auto CG_WIN_CENTER(const std::string &WIN) -> std::string;
auto CG_WIN_HIDE(const std::string &WIN) -> std::string;
auto CG_WIN_DESTROY(const std::string &WIN) -> std::string;
auto CG_WIN_MEMBER(const std::string &WIN, const std::string &MEMBER_CODE)
    -> std::string;
auto AlifJavaScript_Bridge_SendRequest() -> std::string;
auto AlifJavaScript_Bridge_OnNewWindowSendRequest(const std::string &WVObjName)
    -> std::string;
auto Generate_AlifJavaScript() -> std::string;
void CG_INITIALIZATION();
auto CG_WINX_CODE() -> std::string;
auto CODE_GENERATOR_GET_PC_GUI() -> std::string;

extern std::string AlifJavaScript_Bridge;

#endif // GENERATOR_PC_GUI_H
