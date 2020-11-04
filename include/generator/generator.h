//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_GENERATOR_H
#define ALIFC_GENERATOR_H

#include <map>
#include <string>

// General
std::string CPP_ID_DECLARATION;
std::string CPP_GLOBAL;
std::string CPP_OBJ_DECLARATION;
std::string CPP_FUN;
std::string CPP_GLOBAL_FUN;
std::string CPP_CLASS;
// string CPP_AlifJavaScript_Functions;

// Window
std::map<std::pair<std::string, std::string>, std::string>
    CPP_WINDOW; // [window][option] = value

#endif // ALIFC_GENERATOR_H
