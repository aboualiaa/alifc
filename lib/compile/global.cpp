// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#include "general/global.h"

std::string VERSION = "2.0.14";
bool DEBUG = false;
const std::string ALIF_RESERVED[] = {
    "ألف", "أضف", "مكتبة", "واجهة", "_س_",  "نافذة", "إرجاع", "نهاية", "صنف",
    "خاص", "عدد", "نص",    "كائن",  "دالة", "هدم",   "بناء",  "كلما",  "إذا",
    "أو",  "و",   "وإلا",  "سطر",   "أداة", "نقر",   "زر",    "ملصق",  "صحيح",
    "خطأ", "كسر", "متغير", "ثابت",  "منطق", "طرفية"}; // "رئيسية"
const int ALIF_RESERVED_TOTAL = 33;
const std::vector<std::string> DataType_v{"منطق", "نص", "عدد"};
std::string TempToken[1024];
int TempTokenCount = 1;
std::string APP_TYPE = "PC_CONSOLE";
std::map<std::string, bool> ALIF_FLAG_FILE;
std::map<std::string, std::string> ALIF_FLAG_AT_LINE_FILE;
std::map<std::string, bool> CLASS_CONSTRICTOR_FUN_IS_SET;
std::map<std::string, std::string> CLASS_CONSTRICTOR_FUN_AT_LINE;
std::map<std::string, std::string> CLASS_CONSTRICTOR_FUN_ARG_TOTAL;
std::map<std::pair<std::string, int>, std::string>
    CLASS_CONSTRICTOR_FUN_ARG_TYPE;
bool IsInsideClass = false;
std::string TheClass;
std::map<std::string, bool> CLASS_IS_SET;
std::map<std::string, std::string> CLASS_AT_LINE;
std::map<std::pair<std::string, std::string>, bool> CLASS_FUN_IS_SET;
std::map<std::pair<std::string, std::string>, std::string> CLASS_FUN_AT_LINE;
std::map<std::pair<std::string, std::string>, std::string> CLASS_FUN_TYPE;
std::map<std::pair<std::string, std::string>, bool> CLASS_FUN_PRIVATE;
std::map<std::pair<std::string, std::string>, int> CLASS_FUN_ARG_TOTAL;
std::map<std::pair<std::string, int>, std::string> CLASS_FUN_ARG_TYPE;
std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_IS_SET;
std::map<std::pair<std::string, std::string>, std::string> CLASS_G_VAR_AT_LINE;
std::map<std::pair<std::string, std::string>, std::string> CLASS_G_VAR_TYPE;
std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_PRIVATE;
std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_IS_CONST;
std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_IS_ARRAY;
std::map<std::pair<std::string, std::string>, bool> OBJ_IS_SET;
std::map<std::pair<std::string, std::string>, std::string> OBJ_AT_LINE;
std::map<std::pair<std::string, std::string>, std::string> OBJ_CLASS;
std::map<std::string, std::string> OBJ_GLOBAL_DECLARATION;
bool IsInsideWindow = false;
std::string TheWindow;
int WIN_TOTAL = 0;
std::string WIN_TOTAL_NAMES[64];
bool MAIN_WIN_IS_SET = false;
std::string MAIN_WIN_AT_LINE;
std::map<std::string, bool> WIN_IS_SET;
std::map<std::string, std::string> WIN_AT_LINE;
std::map<std::string, bool> WIN_IS_WEB;
bool IsInsideFunction = false;
std::string TheFunction;
std::string TheFunction_TYPE;
std::map<std::pair<std::string, std::string>, std::string> RETURN_FUN;
bool IS_CONTROL_FUNCTION_NAME = false;
std::map<std::string, bool> MAIN_FUN_IS_SET;
std::map<std::string, std::string> MAIN_FUN_AT_LINE;
std::map<std::string, bool> G_FUN_IS_SET;
std::map<std::string, std::string> G_FUN_AT_LINE;
std::map<std::string, std::string> G_FUN_TYPE;
std::map<std::string, int> G_FUN_ARG_TOTAL;
std::map<std::pair<std::string, int>, std::string> G_FUN_ARG_TYPE;
int Global_TotalFucntion = 0;
std::map<int, std::string> Global_FunctionNames;
std::map<std::pair<std::string, std::string>, bool> L_FUN_IS_SET;
std::map<std::pair<std::string, std::string>, std::string> L_FUN_AT_LINE;
std::map<std::pair<std::string, std::string>, std::string> L_FUN_TYPE;
std::map<std::pair<std::string, std::string>, int> L_FUN_ARG_TOTAL;
std::map<std::pair<std::string, int>, std::string> L_FUN_ARG_TYPE;
int Win_CurrentTotalFucntion = 0;
std::map<std::string, int> Win_TotalFucntion;
std::map<std::pair<std::string, int>, std::string> Win_FunctionNames;
std::string NEW_FUNCTION_ARG;
std::map<std::pair<std::string, std::string>, bool> L_VAR_IS_SET;
std::map<std::pair<std::string, std::string>, std::string> L_VAR_AT_LINE;
std::map<std::pair<std::string, std::string>, std::string> L_VAR_TYPE;
std::map<std::pair<std::string, std::string>, bool> L_VAR_IS_CONST;
std::map<std::pair<std::string, std::string>, bool> L_VAR_IS_ARRAY;
std::map<std::string, bool> G_VAR_IS_SET;
std::map<std::string, std::string> G_VAR_AT_LINE;
std::map<std::string, std::string> G_VAR_TYPE;
std::map<std::string, bool> G_VAR_IS_CONST;
std::map<std::string, bool> G_VAR_IS_ARRAY;
int G_VAR_TOTAL = 0;
std::map<int, std::string> G_VAR_NAMES;
std::map<std::string, bool> CONTROL_WIN_IS_SET;
std::map<std::string, std::string> CONTROL_WIN_AT_LINE;
std::map<std::pair<std::string, std::string>, bool> CONTROL_IS_SET;
std::map<std::pair<std::string, std::string>, std::string> CONTROL_AT_LINE;
std::map<std::pair<std::string, std::string>, std::string> CONTROL_TYPE;
int ALIF_PARENTHESIS_STATUS = 0;
int ALIF_IF_STATUS = 0;
bool IS_IF_SYNTAX = false;
int ALIF_LOOP_STATUS = 0;
const bool DEBUG_PRINT_ON_SCREEN = false;
bool THIS_IS_ALIF_C_FILE = false;
bool SHOW_FILE_AND_LINE = true;
bool ERROR_PRINT_ON_SCREEN = false;
std::string LOG_MESSAGE_FULL;
std::string CBUFER;
std::string CBUFER_ID;
std::string CBUFER_OBJ;
std::string ScriptSyntaxBuffer;
std::string ScriptBuffer;
bool LIB_INSIDE_CPP_CODE = false;
std::string LIB_LEXER_CG_BUFER;
std::string LIB_PARSER_CG_BUFER;
bool ThisIsJavaScript = false;
std::map<std::string, bool> ALREADY_PARSED_FILE_TOKENS_NOT_PREDEFINED;
std::map<std::string, bool> ALREADY_PARSED_FILE_TOKENS_PREDEFINED;
std::string PATH_FULL_ALIF;
std::string PATH_FULL_BIN;
std::string PATH_FULL_LOG;
std::string PATH_FULL_GCC;
std::string PATH_FULL_CPP;
std::string PATH_FULL_OBJ;
std::string PATH_FULL_RC;
std::string PATH_FULL_ICO;
#if __APPLE__
std::string PATH_FULL_PLIST;
std::string PATH_FULL_BIN_TMP;
#endif
std::string PATH_ABSOLUTE;
std::string working_directory;
std::string PATH_TEMP;
std::string RANDOM;
std::string PATH_FULL_LIB_SETTING;
std::map<std::string, std::string> LIB_FILE_NAME;
std::string PATH_FULL_WINDOW_WEB;
#ifdef _WIN32
std::string path_separator = "\\";
#else
std::string path_separator = "/";
#endif
std::string Compile_ExtraCompile = " ";
std::string Compile_ExtraLink = " ";

std::string PythonInclude_path;
std::string PythonLib_path;
std::string PythonLibName;

void CompileAddExtra_Compile(const std::string &cmd) {
  Compile_ExtraCompile.append(cmd);
}

void CompileAddExtra_Link(const std::string &cmd) {
  Compile_ExtraLink.append(cmd);
}

void PythonSetEnvirenment() {

  // -------------------------------
  // Python cmd: python3 -c "import sys; print(sys.path)"
  // Python includes	-> /usr/include/python3.5
  // Python Libs		->
  // /usr/lib/python3.5/config-3.5m-x86_64-linux-gnu python lib name	->
  // python3.5
  // -------------------------------

  // TODO(aboualiaa): if thos var are empty, then get python paths by cmd.

  std::string buffer = " -I\"" + PythonInclude_path + "\" ";
  CompileAddExtra_Compile(buffer);
  buffer = " -L\"" + PythonLib_path + "\" -l" + PythonLibName + " ";
  CompileAddExtra_Link(buffer);
}
