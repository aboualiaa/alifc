//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_GLOBAL_H
#define ALIFC_GLOBAL_H

#include <map>
#include <string>
#include <vector>

extern std::string VERSION;
extern bool DEBUG;
extern const std::string ALIF_RESERVED[];
extern const int ALIF_RESERVED_TOTAL;
extern const std::vector<std::string> DataType_v;
extern std::string TempToken[1024];
extern int TempTokenCount;
extern std::string APP_TYPE;
extern std::map<std::string, bool> ALIF_FLAG_FILE;
extern std::map<std::string, std::string> ALIF_FLAG_AT_LINE_FILE;
extern std::map<std::string, bool> CLASS_CONSTRICTOR_FUN_IS_SET;
extern std::map<std::string, std::string> CLASS_CONSTRICTOR_FUN_AT_LINE;
extern std::map<std::string, std::string> CLASS_CONSTRICTOR_FUN_ARG_TOTAL;
extern std::map<std::pair<std::string, int>, std::string>
    CLASS_CONSTRICTOR_FUN_ARG_TYPE;
extern bool IsInsideClass;
extern std::string TheClass;
extern std::map<std::string, bool> CLASS_IS_SET;
extern std::map<std::string, std::string> CLASS_AT_LINE;
extern std::map<std::pair<std::string, std::string>, bool> CLASS_FUN_IS_SET;
extern std::map<std::pair<std::string, std::string>, std::string>
    CLASS_FUN_AT_LINE;
extern std::map<std::pair<std::string, std::string>, std::string>
    CLASS_FUN_TYPE;
extern std::map<std::pair<std::string, std::string>, bool> CLASS_FUN_PRIVATE;
extern std::map<std::pair<std::string, std::string>, int> CLASS_FUN_ARG_TOTAL;
extern std::map<std::pair<std::string, int>, std::string> CLASS_FUN_ARG_TYPE;
extern std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_IS_SET;
extern std::map<std::pair<std::string, std::string>, std::string>
    CLASS_G_VAR_AT_LINE;
extern std::map<std::pair<std::string, std::string>, std::string>
    CLASS_G_VAR_TYPE;
extern std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_PRIVATE;
extern std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_IS_CONST;
extern std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_IS_ARRAY;
extern std::map<std::pair<std::string, std::string>, bool> OBJ_IS_SET;
extern std::map<std::pair<std::string, std::string>, std::string> OBJ_AT_LINE;
extern std::map<std::pair<std::string, std::string>, std::string> OBJ_CLASS;
extern std::map<std::string, std::string> OBJ_GLOBAL_DECLARATION;
extern bool IsInsideWindow;
extern std::string TheWindow;
extern int WIN_TOTAL;
extern std::string WIN_TOTAL_NAMES[64];
extern bool MAIN_WIN_IS_SET;
extern std::string MAIN_WIN_AT_LINE;
extern std::map<std::string, bool> WIN_IS_SET;
extern std::map<std::string, std::string> WIN_AT_LINE;
extern std::map<std::string, bool> WIN_IS_WEB;
extern bool IsInsideFunction;
extern std::string TheFunction;
extern std::string TheFunction_TYPE;
extern std::map<std::pair<std::string, std::string>, std::string> RETURN_FUN;
extern bool IS_CONTROL_FUNCTION_NAME;
extern std::map<std::string, bool> MAIN_FUN_IS_SET;
extern std::map<std::string, std::string> MAIN_FUN_AT_LINE;
extern std::map<std::string, bool> G_FUN_IS_SET;
extern std::map<std::string, std::string> G_FUN_AT_LINE;
extern std::map<std::string, std::string> G_FUN_TYPE;
extern std::map<std::string, int> G_FUN_ARG_TOTAL;
extern std::map<std::pair<std::string, int>, std::string> G_FUN_ARG_TYPE;
extern int Global_TotalFucntion;
extern std::map<int, std::string> Global_FunctionNames;
extern std::map<std::pair<std::string, std::string>, bool> L_FUN_IS_SET;
extern std::map<std::pair<std::string, std::string>, std::string> L_FUN_AT_LINE;
extern std::map<std::pair<std::string, std::string>, std::string> L_FUN_TYPE;
extern std::map<std::pair<std::string, std::string>, int> L_FUN_ARG_TOTAL;
extern std::map<std::pair<std::string, int>, std::string> L_FUN_ARG_TYPE;
extern int Win_CurrentTotalFucntion;
extern std::map<std::string, int> Win_TotalFucntion;
extern std::map<std::pair<std::string, int>, std::string> Win_FunctionNames;
extern std::string NEW_FUNCTION_ARG;
extern std::map<std::pair<std::string, std::string>, bool> L_VAR_IS_SET;
extern std::map<std::pair<std::string, std::string>, std::string> L_VAR_AT_LINE;
extern std::map<std::pair<std::string, std::string>, std::string> L_VAR_TYPE;
extern std::map<std::pair<std::string, std::string>, bool> L_VAR_IS_CONST;
extern std::map<std::pair<std::string, std::string>, bool> L_VAR_IS_ARRAY;
extern std::map<std::string, bool> G_VAR_IS_SET;
extern std::map<std::string, std::string> G_VAR_AT_LINE;
extern std::map<std::string, std::string> G_VAR_TYPE;
extern std::map<std::string, bool> G_VAR_IS_CONST;
extern std::map<std::string, bool> G_VAR_IS_ARRAY;
extern int G_VAR_TOTAL;
extern std::map<int, std::string> G_VAR_NAMES;
extern std::map<std::string, bool> CONTROL_WIN_IS_SET;
extern std::map<std::string, std::string> CONTROL_WIN_AT_LINE;
extern std::map<std::pair<std::string, std::string>, bool> CONTROL_IS_SET;
extern std::map<std::pair<std::string, std::string>, std::string>
    CONTROL_AT_LINE;
extern std::map<std::pair<std::string, std::string>, std::string> CONTROL_TYPE;
extern int ALIF_PARENTHESIS_STATUS;
extern int ALIF_IF_STATUS;
extern bool IS_IF_SYNTAX;
extern int ALIF_LOOP_STATUS;
extern const bool DEBUG_PRINT_ON_SCREEN;
extern bool THIS_IS_ALIF_C_FILE;
extern bool SHOW_FILE_AND_LINE;
extern bool ERROR_PRINT_ON_SCREEN;
extern std::string LOG_MESSAGE_FULL;
extern std::string CBUFER;
extern std::string CBUFER_ID;
extern std::string CBUFER_OBJ;
extern std::string ScriptSyntaxBuffer;
extern std::string ScriptBuffer;
extern bool LIB_INSIDE_CPP_CODE;
extern std::string LIB_LEXER_CG_BUFER;
extern std::string LIB_PARSER_CG_BUFER;
extern bool ThisIsJavaScript;
extern std::map<std::string, bool> ALREADY_PARSED_FILE_TOKENS_NOT_PREDEFINED;
extern std::map<std::string, bool> ALREADY_PARSED_FILE_TOKENS_PREDEFINED;
extern std::string PATH_FULL_ALIF;
extern std::string PATH_FULL_BIN;
extern std::string PATH_FULL_LOG;
extern std::string PATH_FULL_GCC;
extern std::string PATH_FULL_CPP;
extern std::string PATH_FULL_OBJ;
extern std::string PATH_FULL_RC;
extern std::string PATH_FULL_ICO;
#if __APPLE__
extern std::string PATH_FULL_PLIST;
extern std::string PATH_FULL_BIN_TMP;
#endif
extern std::string PATH_ABSOLUTE;
extern std::string PATH_WORKING;
extern std::string PATH_TEMP;
extern std::string RANDOM;
extern std::string PATH_FULL_LIB_SETTING;
extern std::map<std::string, std::string> LIB_FILE_NAME;
extern std::string PATH_FULL_WINDOW_WEB;
#ifdef _WIN32
std::string SEPARATION = "\\";
#else
extern std::string SEPARATION;
#endif
extern std::string Compile_ExtraCompile;
extern std::string Compile_ExtraLink;
extern std::string PythonInclude_path;
extern std::string PythonLib_path;
extern std::string PythonLibName;

void CompileAddExtra_Link(const std::string &cmd);
void CompileAddExtra_Compile(const std::string &cmd);
void PythonSetEnvirenment();

#endif // ALIFC_GLOBAL_H
