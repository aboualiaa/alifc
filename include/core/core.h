//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef CORE_CORE_H
#define CORE_CORE_H

#include <sstream>

#include "general/headers.h"
#include "general/log.h"
#include "utf8/core.h"
#include "utf8/utf8.h"

auto ID_GENERATOR() -> int;

auto replace(std::string &str, const std::string &from, const std::string &to)
    -> bool;
auto replace_end(std::string &str, const std::string &from,
                 const std::string &to) -> bool;
auto substr_utf8(const std::string &originalString, int Position, int MaxLen)
    -> std::string;
auto IntToString(int INT_VAL) -> std::string;
auto CONVERT_STRING_ARRAY_TO_STRING(std::string STRING_ARRAY_VAL[1024],
                                    int LONG) -> std::string;
auto CONVERT_WCHAT_T_TO_STRING(wchar_t *WCHART_T_VAL) -> std::string;
auto CONVERT_CHAR_TO_STRING(char *CHART_VAL) -> std::string;

extern int Generated_ID;
extern int useconst;
extern int zeroterminated;
extern const std::string base64_chars;
extern std::map<std::string, std::string> ID;         // abc[var] = V1000d
extern std::map<std::string, std::string> Global_ID;  // abc[var] = G_V1000d
extern std::map<std::string, std::string> Control_ID; // abc[var] = C_V1000d
extern std::map<std::string, std::string> Obj_ID;     // abc[var] = OBJ_V1000d
extern std::map<std::string, std::string>
    GlobalObj_ID; // abc[var] = G_OBJ_V1000
extern std::string IsValidVar_Type;
extern std::string C_LAST_ARG;

auto BinaryToC_myfgetc(FILE *f) -> int;
auto BinaryToC_str2upr(char *s) -> char *;
void BinaryToC_process(const char *ifname, const char *ofname);
void BinaryToC(const std::string &FileIn, const std::string &FileOut);
static inline auto is_base64(unsigned char c) -> bool;
auto base64_encode(unsigned char const *bytes_to_encode, unsigned int in_len)
    -> std::string;
auto BinaryToBase64(const std::string &FileIn) -> std::string;
void SET_OBJ_C_NAME(const std::string &VAR);
void SET_GLOBAL_OBJ_C_NAME(const std::string &VAR);
void SET_C_NAME(const std::string &VAR);
void SET_GLOBAL_C_NAME(const std::string &VAR);
void SET_CONTROL_C_NAME(const std::string &VAR);
auto IsInArray_v(const std::string &value,
                 const std::vector<std::string> &array) -> bool;
auto IsDataType(const std::string &value) -> bool;
auto CharCount_utf8(std::string LINE8, lex::Token *o_tokens) -> int;
auto GET_REAL_LINE_MID(int START, int TOKEN_POSITION, lex::Token *o_tokens)
    -> std::string;
auto IsValidStringFormat(const std::string &STRING, lex::Token *o_tokens)
    -> bool;
auto REMOVE_DOUBLE_SPACE(const std::string &LINE_BUFFER, lex::Token *o_tokens)
    -> std::string;
auto IsValidDigit(const std::string &DIGIT, bool FLOAT, lex::Token *o_tokens)
    -> bool;
auto CAN_ADD_OPERATION_HERE(const std::string &TOKEN_LAST) -> bool;
auto CAN_ADD_VAR_HERE(const std::string &TOKEN_LAST) -> bool;
auto CAN_ADD_FUN_HERE(const std::string &TOKEN_LAST) -> bool;
auto CAN_ADD_PARENTHESIS_OPEN_HERE(const std::string &TOKEN_LAST) -> bool;
auto IsValidVar(const std::string &Var, lex::Token *o_tokens) -> bool;
auto CAN_ADD_PARENTHESIS_CLOSE_HERE(const std::string &TOKEN_LAST) -> bool;
auto CAN_ADD_DIGIT_HERE(const std::string &TOKEN_LAST) -> bool;
auto GET_TXT_FROM_STRING(const std::string &STRING, lex::Token *o_tokens)
    -> std::string;
void CheckForSameGlobalID(const std::string &Name, lex::Token *o_tokens);
auto IsValidName(const std::string &Name, lex::Token *o_tokens) -> bool;
void ADD_FUN(bool GLOBAL, const std::string &WIN_NAME,
             const std::string &FUN_NAME, const std::string &TYPE, int Line,
             lex::Token *o_tokens);
void SetNewVar(bool IsGlobal, const std::string &TmpWindow,
               const std::string &TmpFunction, const std::string &VarName,
               const std::string &VarDataType, bool IsConstant, bool IsArray,
               int Line, lex::Token *o_tokens);
void SetNewVarClass(bool IsGlobal, bool IsPrivate, const std::string &ClassName,
                    const std::string &FunctionName, const std::string &VarName,
                    const std::string &VarDataType, bool IsConstant,
                    bool IsArray, int Line, lex::Token *o_tokens);
auto GetSyntaxDataType(std::string Token[1024], int Position,
                       lex::Token *o_tokens) -> std::string;
void ADD_FUN_CLASS(bool PRIVATE, const std::string &CLASS_NAME,
                   const std::string &FUN_NAME, const std::string &TYPE,
                   int Line, lex::Token *o_tokens);
auto CHECK_NEW_FUN_SYNTAX(bool GLOBAL, std::string SYNTAX[1024],
                          int SYNTAX_LONG, const std::string &TmpWindow,
                          const std::string &TmpFunction, lex::Token *o_tokens)
    -> std::string;
auto CheckForSyntax(
    const std::string &OBJECTIF_TYPE, // OBJECTIF_TYPE
    bool ACCEPT_REF_WIN_WIDGET, // Accept Using Reference إلى Window:Controls
    bool ACCEPT_REF_WIN_FUN,    // Accept Using Reference إلى Window:Function
    bool ACCEPT_REF_GLOBAL_FUN, // Accept Using Reference إلى Global Functions
    bool ACCEPT_REF_LOCAL_FUN,  // Accept Using Reference إلى Local Functions
    bool ACCEPT_REF_GLOBAL_VAR, // Accept Using Reference إلى Global VAR
    bool ACCEPT_REF_LOCAL_VAR,  // Accept Using Reference إلى Local VAR
    bool ACCEPT_STR_TO_INT,     // Accept Convertion من نص إلى Int
    bool ACCEPT_INT_TO_STRING,  // Accept Convertion من عدد إلى String
    std::string SYNTAX[1024],   // SYNTAX[] string
    int SYNTAX_LONG,            // SYNTAX_LONG int
    const std::string &TMP_WIN_OR_CLASS, // a = b + win:fun(2+2) + class:fun(x)
    const std::string &TmpFunction,      // a = b + win/class:fun(2+2)
    lex::Token *o_tokens) -> std::string;
auto CHECK_CALL_FUN_ARG(bool CALL_FUN_GLOBAL,
                        const std::string &CALL_WIN_OR_CLASS,
                        const std::string &CALL_FUN, int CALL_IS_CLASS,
                        const std::string &FROM_WIN_OR_CLASS,
                        const std::string &FROM_FUN, std::string SYNTAX[1024],
                        int SYNTAX_LONG, lex::Token *o_tokens) -> std::string;
void FINAL_CURRENT_FILE_CODE_CHECKING(lex::Token *o_tokens);
void FINAL_APPLICATION_CODE_CHECKING(lex::Token *o_tokens, bool FIRST_FILE);

#endif // CORE_CORE_H
