//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_GLOBAL_H
#define ALIFC_GLOBAL_H

#include <map>
#include <string>
#include <vector>

std::string VERSION = "2.0.14";

bool DEBUG = false;

// ألف أضف مكتبة رئيسية _س_ واجهة خاص
// نهاية كلما نافدة دالة عدد نص كائن إذا و أو سطر إرجاع صنف أداة نقر زر نص
// ملصق إظهار إخفاء تدمير عنوان نص تجميد عرض محتوى ارتفاع أفصول أرتوب

static const std::string ALIF_RESERVED[] = {
    "ألف", "أضف", "مكتبة", "واجهة", "_س_",  "نافذة", "إرجاع", "نهاية", "صنف",
    "خاص", "عدد", "نص",    "كائن",  "دالة", "هدم",   "بناء",  "كلما",  "إذا",
    "أو",  "و",   "وإلا",  "سطر",   "أداة", "نقر",   "زر",    "ملصق",  "صحيح",
    "خطأ", "كسر", "متغير", "ثابت",  "منطق", "طرفية"}; // "رئيسية"

// "عرض", "محتوى", "ارتفاع", "أفصول", "أرتوب", "تدمير", "عنوان", "تجميد",
// "إظهار", "إخفاء"

static const int ALIF_RESERVED_TOTAL = 33;

static const std::vector<std::string> DataType_v{"منطق", "نص", "عدد"};

// -----------------------------------------------------------
// Lexic Tokens Class
// Create Obj for every Alif Source files
// -----------------------------------------------------------

std::string TempToken[1024];
int TempTokenCount = 1;

// ----------------------------------
// Alif Global Language Variables
// ----------------------------------

static std::string APP_TYPE = "PC_CONSOLE";

// ----------------------------------
// Flag
// ----------------------------------

static std::map<std::string, bool>
    ALIF_FLAG_FILE; // alif_flag[full_file_path] = true or false
static std::map<std::string, std::string>
    ALIF_FLAG_AT_LINE_FILE; // alif_flag[full_file_path] = at_line

// ----------------------------------
// صنف
// ----------------------------------

static std::map<std::string, bool>
    CLASS_CONSTRICTOR_FUN_IS_SET; // abc[class] = main_func true or false
static std::map<std::string, std::string>
    CLASS_CONSTRICTOR_FUN_AT_LINE; // abc[class] = main_func_at_line
static std::map<std::string, std::string>
    CLASS_CONSTRICTOR_FUN_ARG_TOTAL; // abc[class] = total args
static std::map<std::pair<std::string, int>, std::string>
    CLASS_CONSTRICTOR_FUN_ARG_TYPE; // abc[class][arg number] = arg type

static bool IsInsideClass = false;
static std::string TheClass;
static std::map<std::string, bool>
    CLASS_IS_SET; // abc['class name'] = already set ?
static std::map<std::string, std::string>
    CLASS_AT_LINE; // abc['class name'] = class at line

static std::map<std::pair<std::string, std::string>, bool>
    CLASS_FUN_IS_SET; // abc[class][fun] = class fun already set ?
static std::map<std::pair<std::string, std::string>, std::string>
    CLASS_FUN_AT_LINE; // abc[class][fun] = class fun line number
static std::map<std::pair<std::string, std::string>, std::string>
    CLASS_FUN_TYPE; // abc[class][fun] = class fun type
static std::map<std::pair<std::string, std::string>, bool>
    CLASS_FUN_PRIVATE; // abc[class][fun] = class fun private ?
static std::map<std::pair<std::string, std::string>, int>
    CLASS_FUN_ARG_TOTAL; // abc[class][fun] = global total args
static std::map<std::pair<std::string, int>, std::string>
    CLASS_FUN_ARG_TYPE; // abc[class + fun][arg number] = arg type

static std::map<std::pair<std::string, std::string>, bool>
    CLASS_G_VAR_IS_SET; // abc[class][var] = global var already set ?
static std::map<std::pair<std::string, std::string>, std::string>
    CLASS_G_VAR_AT_LINE; // abc[class][var] = global var line number
static std::map<std::pair<std::string, std::string>, std::string>
    CLASS_G_VAR_TYPE; // abc[class][var] = global var type
static std::map<std::pair<std::string, std::string>, bool>
    CLASS_G_VAR_PRIVATE; // abc[class][var] = global private ?
static std::map<std::pair<std::string, std::string>, bool>
    CLASS_G_VAR_IS_CONST; // abc[class][var] = global var Constant
static std::map<std::pair<std::string, std::string>, bool> CLASS_G_VAR_IS_ARRAY;

// ----------------------------------
// كائن
// ----------------------------------

static std::map<std::pair<std::string, std::string>, bool>
    OBJ_IS_SET; // abc[win + fun][obj] = already set ?
static std::map<std::pair<std::string, std::string>, std::string>
    OBJ_AT_LINE; // abc[win + fun][obj] = line number
static std::map<std::pair<std::string, std::string>, std::string>
    OBJ_CLASS; // abc[win + fun][obj] = base class
static std::map<std::string, std::string>
    OBJ_GLOBAL_DECLARATION; // abc[class] = Obj1; Obj2;...

// ----------------------------------
// نافدة
// ----------------------------------

static bool IsInsideWindow = false;
static std::string TheWindow;

int WIN_TOTAL = 0;
std::string WIN_TOTAL_NAMES[64];

// ----------------------------------
// نافدة رئيسية
// ----------------------------------

static bool MAIN_WIN_IS_SET = false;
static std::string MAIN_WIN_AT_LINE;

// ----------------------------------
// نافدة
// ----------------------------------

static std::map<std::string, bool>
    WIN_IS_SET; // abc['window_name'] = already set ?
static std::map<std::string, std::string>
    WIN_AT_LINE; // abc['window_name'] = func_at_line
static std::map<std::string, bool> WIN_IS_WEB; // abc['window_name'] = Web UI ?

// ----------------------------------
// دالة
// ----------------------------------

static bool IsInsideFunction = false;
static std::string TheFunction;
static std::string TheFunction_TYPE;
static std::map<std::pair<std::string, std::string>, std::string>
    RETURN_FUN; // abc[win][fun] = return is ok ? "OK", "IF"
static bool IS_CONTROL_FUNCTION_NAME = false;

// ----------------------------------
// دالة رئيسية
// ----------------------------------

static std::map<std::string, bool>
    MAIN_FUN_IS_SET; // abc['window_name'] = main_func true or false
static std::map<std::string, std::string>
    MAIN_FUN_AT_LINE; // abc['window_name'] = main_func_at_line

// ----------------------------------
// دالة
// ----------------------------------

static std::map<std::string, bool>
    G_FUN_IS_SET; // abc[gfun] = global fun already set ?
static std::map<std::string, std::string>
    G_FUN_AT_LINE; // abc[gfun] = global fun line number
static std::map<std::string, std::string>
    G_FUN_TYPE; // abc[gfun] = global fun type
static std::map<std::string, int>
    G_FUN_ARG_TOTAL; // abc[gfun] = global total args
static std::map<std::pair<std::string, int>, std::string>
    G_FUN_ARG_TYPE; // abc[gfun][arg number] = arg type
int Global_TotalFucntion = 0;
static std::map<int, std::string>
    Global_FunctionNames; // abc[global fun number] = func name

static std::map<std::pair<std::string, std::string>, bool>
    L_FUN_IS_SET; // abc[window][fun] = local fun already set ?
static std::map<std::pair<std::string, std::string>, std::string>
    L_FUN_AT_LINE; // abc[window][fun] = local fun line number
static std::map<std::pair<std::string, std::string>, std::string>
    L_FUN_TYPE; // abc[window][fun] = local fun type
static std::map<std::pair<std::string, std::string>, int>
    L_FUN_ARG_TOTAL; // abc[window][fun] = global total args
static std::map<std::pair<std::string, int>, std::string>
    L_FUN_ARG_TYPE; // abc[window + fun][arg number] = arg type

int Win_CurrentTotalFucntion = 0;
static std::map<std::string, int>
    Win_TotalFucntion; // abc[window] = total functions
static std::map<std::pair<std::string, int>, std::string>
    Win_FunctionNames; // abc[window][fun number] = func name

static std::string NEW_FUNCTION_ARG = "";

// -----------------------------------------------------------
// VARs
// -----------------------------------------------------------

// Local var

static std::map<std::pair<std::string, std::string>, bool>
    L_VAR_IS_SET; // abc[window + func][var] = local var already set ?
static std::map<std::pair<std::string, std::string>, std::string>
    L_VAR_AT_LINE; // abc[window + func][var] = local var line number
static std::map<std::pair<std::string, std::string>, std::string>
    L_VAR_TYPE; // abc[window + func][var] = local var type
static std::map<std::pair<std::string, std::string>, bool>
    L_VAR_IS_CONST; // abc[window + func][var] = local var Constant
static std::map<std::pair<std::string, std::string>, bool> L_VAR_IS_ARRAY;

// Global var

static std::map<std::string, bool>
    G_VAR_IS_SET; // abc[var] = global var already set ?
static std::map<std::string, std::string>
    G_VAR_AT_LINE; // abc[var] = global var line number
static std::map<std::string, std::string>
    G_VAR_TYPE; // abc[var] = global var type
static std::map<std::string, bool>
    G_VAR_IS_CONST; // abc[var] = global var Constant
static std::map<std::string, bool> G_VAR_IS_ARRAY;
static int G_VAR_TOTAL = 0;                    // Total of global vars
static std::map<int, std::string> G_VAR_NAMES; // abc[var] = var_name

// -----------------------------------------------------------
// CONTROLS TABLE
// -----------------------------------------------------------

static std::map<std::string, bool>
    CONTROL_WIN_IS_SET; // abc[win-control] = already set ?
static std::map<std::string, std::string>
    CONTROL_WIN_AT_LINE; // abc[win-control] = line number
static std::map<std::pair<std::string, std::string>, bool>
    CONTROL_IS_SET; // abc[window][control] = already set ?
static std::map<std::pair<std::string, std::string>, std::string>
    CONTROL_AT_LINE; // abc[window][control] = line number
static std::map<std::pair<std::string, std::string>, std::string>
    CONTROL_TYPE; // abc[window][control] = type

// ----------------------------------
// PARENTHESIS
// ----------------------------------

static int ALIF_PARENTHESIS_STATUS = 0;

// ----------------------------------
// IF
// ----------------------------------

static int ALIF_IF_STATUS = 0;
static bool IS_IF_SYNTAX = false;

// ----------------------------------
// LOOP
// ----------------------------------

static int ALIF_LOOP_STATUS = 0;

// -----------------------------------------------------------
// DEBUG / ERROR / LOG
// -----------------------------------------------------------

// Debug

static const bool DEBUG_PRINT_ON_SCREEN = false;
bool THIS_IS_ALIF_C_FILE = false;
bool SHOW_FILE_AND_LINE = true;

// Error

bool ERROR_PRINT_ON_SCREEN = false;

// Log
std::string LOG_MESSAGE_FULL = "";

// -----------------------------------------------------------
// CPP BUFERs
// -----------------------------------------------------------

std::string CBUFER;
std::string CBUFER_ID;
std::string CBUFER_OBJ;
std::string ScriptSyntaxBuffer;
std::string ScriptBuffer;

// -----------------------------------------------------------
// C++ Code Inside Alif Code
// -----------------------------------------------------------

static bool LIB_INSIDE_CPP_CODE = false;
std::string LIB_LEXER_CG_BUFER;
std::string LIB_PARSER_CG_BUFER;
bool ThisIsJavaScript = false;

// -----------------------------------------------------------
// ALIF COMPILER VARs
// -----------------------------------------------------------

static std::map<std::string, bool> ALREADY_PARSED_FILE_TOKENS_NOT_PREDEFINED;
static std::map<std::string, bool> ALREADY_PARSED_FILE_TOKENS_PREDEFINED;

std::string PATH_FULL_ALIF; // Desktop/myapp.alif
std::string PATH_FULL_BIN;  // Desktop/mybin.bin
std::string PATH_FULL_LOG;  // Desktop/myapp.log

std::string PATH_FULL_GCC; // Linux : 'gcc' | Win : c:\Alif\bin\gcc.exe
std::string PATH_FULL_CPP; // tmp/123456789.cpp
std::string PATH_FULL_OBJ; // tmp/123456789.o
std::string PATH_FULL_RC;  // tmp/123456789.rc
std::string
    PATH_FULL_ICO; // Mac: /usr/share/aliflang/alif.ics | Win: c:\Alif\alif.ico
#if __APPLE__
std::string PATH_FULL_PLIST;   // Mac only
std::string PATH_FULL_BIN_TMP; // Tmp/mybin.bin
#endif

std::string PATH_ABSOLUTE;
std::string PATH_WORKING;

std::string PATH_TEMP; // /usr/tmp
std::string RANDOM;    // 1234

std::string PATH_FULL_LIB_SETTING; // 'gcc' | c:\Alif\aliflib\aliflib.inf
std::map<std::string, std::string> LIB_FILE_NAME;

// Complet path of Web UI window (HTML5) file
// Used by parser #window_web
std::string PATH_FULL_WINDOW_WEB;

#ifdef _WIN32
std::string SEPARATION = "\\";
#else
std::string SEPARATION = "/";
#endif

// -----------------------------------------------------------
// Compile Extra commands
// -----------------------------------------------------------

std::string Compile_ExtraCompile = " "; // -I/...
std::string Compile_ExtraLink = " ";    // -L\"/...\" -lmylib...

void CompileAddExtra_Compile(const std::string &cmd);

void CompileAddExtra_Link(const std::string &cmd);

std::string PythonInclude_path = "";
std::string PythonLib_path = "";
std::string PythonLibName = "";

void PythonSetEnvirenment();

#endif // ALIFC_GLOBAL_H
