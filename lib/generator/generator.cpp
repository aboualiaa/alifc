// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#include "generator/generator.h"

std::string CPP_ID_DECLARATION;
std::string CPP_GLOBAL;
std::string CPP_OBJ_DECLARATION;
std::string CPP_FUN;
std::string CPP_GLOBAL_FUN;
std::string CPP_CLASS;
std::map<std::pair<std::string, std::string>, std::string> CPP_WINDOW;

#include "pc_console.cpp" // PC Console
#include "pc_gui.cpp" // PC GUI
#include "phone_android.cpp" // Phone Android
