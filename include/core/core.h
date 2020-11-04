//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_CORE_H
#define ALIFC_CORE_H

#include <sstream>

#include "../lib/utf8.h"
#include "../lib/utf8/core.h"
#include "general/headers.h"
#include "general/log.h"

int Generated_ID = 10000;
int ID_GENERATOR();

bool replace(std::string &str, const std::string &from, const std::string &to);
bool replace_end(std::string &str, const std::string &from,
                 const std::string &to);
std::string substr_utf8(const std::string &originalString, int Position,
                        int MaxLen);
std::string IntToString(int INT_VAL);
std::string CONVERT_STRING_ARRAY_TO_STRING(std::string STRING_ARRAY_VAL[1024],
                                           int LONG);
std::string CONVERT_WCHAT_T_TO_STRING(wchar_t *WCHART_T_VAL);
std::string CONVERT_CHAR_TO_STRING(char *CHART_VAL);

int useconst = 0;
int zeroterminated = 0;

int BinaryToC_myfgetc(FILE *f);

char *BinaryToC_str2upr(char *s);

void BinaryToC_process(const char *ifname, const char *ofname);
void BinaryToC(const std::string &FileIn, const std::string &FileOut);

static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz"
                                        "0123456789+/";

static inline bool is_base64(unsigned char c);

std::string base64_encode(unsigned char const *bytes_to_encode,
                          unsigned int in_len);
std::string BinaryToBase64(const std::string &FileIn);

static std::map<std::string, std::string> ID;         // abc[var] = V1000
static std::map<std::string, std::string> Global_ID;  // abc[var] = G_V1000
static std::map<std::string, std::string> Control_ID; // abc[var] = C_V1000
static std::map<std::string, std::string> Obj_ID;     // abc[var] = OBJ_V1000
static std::map<std::string, std::string>
    GlobalObj_ID; // abc[var] = G_OBJ_V1000

void SET_OBJ_C_NAME(const std::string &VAR);

void SET_GLOBAL_OBJ_C_NAME(const std::string &VAR);

void SET_C_NAME(const std::string &VAR);

void SET_GLOBAL_C_NAME(const std::string &VAR);

void SET_CONTROL_C_NAME(const std::string &VAR);

bool IsInArray_v(const std::string &value,
                 const std::vector<std::string> &array);

bool IsDataType(const std::string &value);

int CharCount_utf8(std::string LINE8, CLASS_TOKEN *o_tokens);

std::string GET_REAL_LINE_MID(int START, int TOKEN_POSITION,
                              CLASS_TOKEN *o_tokens);

bool IsValidStringFormat(const std::string &STRING, CLASS_TOKEN *o_tokens);

std::string REMOVE_DOUBLE_SPACE(const std::string &LINE_BUFFER,
                                CLASS_TOKEN *o_tokens);

bool IsValidDigit(const std::string &DIGIT, bool FLOAT, CLASS_TOKEN *o_tokens);

bool CAN_ADD_OPERATION_HERE(const std::string &TOKEN_LAST);
bool CAN_ADD_VAR_HERE(const std::string &TOKEN_LAST);
bool CAN_ADD_FUN_HERE(const std::string &TOKEN_LAST);
bool CAN_ADD_PARENTHESIS_OPEN_HERE(const std::string &TOKEN_LAST);

std::string IsValidVar_Type = "عادم";

bool IsValidVar(const std::string &Var, CLASS_TOKEN *o_tokens);

bool CAN_ADD_PARENTHESIS_CLOSE_HERE(const std::string &TOKEN_LAST);
bool CAN_ADD_DIGIT_HERE(const std::string &TOKEN_LAST);
std::string GET_TXT_FROM_STRING(const std::string &STRING,
                                CLASS_TOKEN *o_tokens);

void CheckForSameGlobalID(const std::string &Name, CLASS_TOKEN *o_tokens);

bool IsValidName(const std::string &Name, CLASS_TOKEN *o_tokens);

void ADD_FUN(bool GLOBAL, const std::string &WIN_NAME,
             const std::string &FUN_NAME, const std::string &TYPE, int Line,
             CLASS_TOKEN *o_tokens);

void SetNewVar(bool IsGlobal, const std::string &TmpWindow,
               const std::string &TmpFunction, const std::string &VarName,
               const std::string &VarDataType, bool IsConstant, bool IsArray,
               int Line, CLASS_TOKEN *o_tokens);

void SetNewVarClass(bool IsGlobal, bool IsPrivate, const std::string &ClassName,
                    const std::string &FunctionName, const std::string &VarName,
                    const std::string &VarDataType, bool IsConstant,
                    bool IsArray, int Line, CLASS_TOKEN *o_tokens);

std::string GetSyntaxDataType(std::string Token[1024], int Position,
                              CLASS_TOKEN *o_tokens);

void ADD_FUN_CLASS(bool PRIVATE, const std::string &CLASS_NAME,
                   const std::string &FUN_NAME, const std::string &TYPE,
                   int Line, CLASS_TOKEN *o_tokens);

std::string C_LAST_ARG;

auto CHECK_NEW_FUN_SYNTAX(bool GLOBAL, std::string SYNTAX[1024],
                          int SYNTAX_LONG, const std::string &TmpWindow,
                          const std::string &TmpFunction, CLASS_TOKEN *o_tokens)
    -> std::string;

std::string CheckForSyntax(
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
    CLASS_TOKEN *o_tokens);

auto CHECK_CALL_FUN_ARG(bool CALL_FUN_GLOBAL,
                        const std::string &CALL_WIN_OR_CLASS,
                        const std::string &CALL_FUN, int CALL_IS_CLASS,
                        const std::string &FROM_WIN_OR_CLASS,
                        const std::string &FROM_FUN, std::string SYNTAX[1024],
                        int SYNTAX_LONG, CLASS_TOKEN *o_tokens) -> std::string;

void FINAL_CURRENT_FILE_CODE_CHECKING(CLASS_TOKEN *o_tokens);

void FINAL_APPLICATION_CODE_CHECKING(CLASS_TOKEN *o_tokens, bool FIRST_FILE);

#endif // ALIFC_CORE_H