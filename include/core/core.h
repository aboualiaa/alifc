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
string substr_utf8(string originalString, int Position, int MaxLen);
string IntToString(int INT_VAL);
string CONVERT_STRING_ARRAY_TO_STRING(string STRING_ARRAY_VAL[1024], int LONG);
string CONVERT_WCHAT_T_TO_STRING(wchar_t *WCHART_T_VAL);
string CONVERT_CHAR_TO_STRING(char *CHART_VAL);

int useconst = 0;
int zeroterminated = 0;

int BinaryToC_myfgetc(FILE *f);

char *BinaryToC_str2upr(char *s);

void BinaryToC_process(const char *ifname, const char *ofname);
void BinaryToC(string FileIn, string FileOut);

static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz"
                                        "0123456789+/";

static inline bool is_base64(unsigned char c);

std::string base64_encode(unsigned char const *bytes_to_encode,
                          unsigned int in_len);
string BinaryToBase64(string FileIn);

static std::map<string, string> ID;           // abc[var] = V1000
static std::map<string, string> Global_ID;    // abc[var] = G_V1000
static std::map<string, string> Control_ID;   // abc[var] = C_V1000
static std::map<string, string> Obj_ID;       // abc[var] = OBJ_V1000
static std::map<string, string> GlobalObj_ID; // abc[var] = G_OBJ_V1000

void SET_OBJ_C_NAME(string VAR);

void SET_GLOBAL_OBJ_C_NAME(string VAR);

void SET_C_NAME(string VAR);

void SET_GLOBAL_C_NAME(string VAR);

void SET_CONTROL_C_NAME(string VAR);

bool IsInArray_v(const std::string &value, const std::vector<string> &array);

bool IsDataType(const std::string &value);

int CharCount_utf8(string LINE8, CLASS_TOKEN *o_tokens);

string GET_REAL_LINE_MID(int START, int TOKEN_POSITION, CLASS_TOKEN *o_tokens);

bool IsValidStringFormat(string STRING, CLASS_TOKEN *o_tokens);

string REMOVE_DOUBLE_SPACE(string LINE_BUFFER, CLASS_TOKEN *o_tokens);

bool IsValidDigit(string DIGIT, bool FLOAT, CLASS_TOKEN *o_tokens);

bool CAN_ADD_OPERATION_HERE(string TOKEN_LAST);

bool CAN_ADD_VAR_HERE(string TOKEN_LAST);

bool CAN_ADD_FUN_HERE(string TOKEN_LAST);

bool CAN_ADD_PARENTHESIS_OPEN_HERE(string TOKEN_LAST);

string IsValidVar_Type = "عادم";

bool IsValidVar(string Var, CLASS_TOKEN *o_tokens);

bool CAN_ADD_PARENTHESIS_CLOSE_HERE(string TOKEN_LAST);

bool CAN_ADD_DIGIT_HERE(string TOKEN_LAST);

string GET_TXT_FROM_STRING(string STRING, CLASS_TOKEN *o_tokens);

void CheckForSameGlobalID(string Name, CLASS_TOKEN *o_tokens);

bool IsValidName(string Name, CLASS_TOKEN *o_tokens);

void ADD_FUN(bool GLOBAL, string WIN_NAME, string FUN_NAME, string TYPE,
             int Line, CLASS_TOKEN *o_tokens);

void SetNewVar(bool IsGlobal, string TmpWindow, string TmpFunction,
               string VarName, string VarDataType, bool IsConstant,
               bool IsArray, int Line, CLASS_TOKEN *o_tokens);

void SetNewVarClass(bool IsGlobal, bool IsPrivate, string ClassName,
                    string FunctionName, string VarName, string VarDataType,
                    bool IsConstant, bool IsArray, int Line,
                    CLASS_TOKEN *o_tokens);

string GetSyntaxDataType(string Token[1024], int Position,
                         CLASS_TOKEN *o_tokens);

void ADD_FUN_CLASS(bool PRIVATE, string CLASS_NAME, string FUN_NAME,
                   string TYPE, int Line, CLASS_TOKEN *o_tokens);

string C_LAST_ARG;

string
CHECK_NEW_FUN_SYNTAX(bool GLOBAL, string SYNTAX[1024], int SYNTAX_LONG,
                     string TmpWindow,   // fun1 { a = b + win:fun2(x) + z }
                     string TmpFunction, // fun1 { a = b + win:fun2(x) + z }
                     CLASS_TOKEN *o_tokens);

string CheckForSyntax(
    string OBJECTIF_TYPE,       // OBJECTIF_TYPE
    bool ACCEPT_REF_WIN_WIDGET, // Accept Using Reference إلى Window:Controls
    bool ACCEPT_REF_WIN_FUN,    // Accept Using Reference إلى Window:Function
    bool ACCEPT_REF_GLOBAL_FUN, // Accept Using Reference إلى Global Functions
    bool ACCEPT_REF_LOCAL_FUN,  // Accept Using Reference إلى Local Functions
    bool ACCEPT_REF_GLOBAL_VAR, // Accept Using Reference إلى Global VAR
    bool ACCEPT_REF_LOCAL_VAR,  // Accept Using Reference إلى Local VAR
    bool ACCEPT_STR_TO_INT,     // Accept Convertion من نص إلى Int
    bool ACCEPT_INT_TO_STRING,  // Accept Convertion من عدد إلى String
    string SYNTAX[1024],        // SYNTAX[] string
    int SYNTAX_LONG,            // SYNTAX_LONG int
    string TMP_WIN_OR_CLASS,    // a = b + win:fun(2+2) + class:fun(x)
    string TmpFunction,         // a = b + win/class:fun(2+2)
    CLASS_TOKEN *o_tokens);

string CHECK_CALL_FUN_ARG(
    bool CALL_FUN_GLOBAL,
    string CALL_WIN_OR_CLASS, // win1/class1 { fun1(int a) } | win2 { fun2{ عدد
                              // b; fun1(b) } } ==> win1
    string CALL_FUN, // win1 { fun1(int a) } | win2 { fun2{ عدد b; fun1(b) } }
                     // ==> fun1
    int CALL_IS_CLASS, // 0 = non class, 1 constructor, 2 = الدالة member, ل
                       // Message when new obj
    string FROM_WIN_OR_CLASS, // win1 { fun1(int a) } | win2 { fun2{ عدد b;
                              // fun1(b) } } ==> win2
    string FROM_FUN, // win1 { fun1(int a) } | win2 { fun2{ عدد b; fun1(b) } }
                     // ==> fun2
    string SYNTAX[1024], int SYNTAX_LONG, CLASS_TOKEN *o_tokens);

void FINAL_CURRENT_FILE_CODE_CHECKING(CLASS_TOKEN *o_tokens);

void FINAL_APPLICATION_CODE_CHECKING(CLASS_TOKEN *o_tokens, bool FIRST_FILE);

#endif // ALIFC_CORE_H
