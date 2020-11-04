//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef GENERAL_SETUP_H
#define GENERAL_SETUP_H

// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#ifdef _WIN32

#include <direct.h> // getcwd (Get current working directory)
#define GetCurrentDir _getcwd

#include <string>
#include <windows.h> // Get Working Path by Win32 API

//#include <w32api.h>
//#include <Winbase.h>
#include <stdlib.h>  // Get Temp envirenemt by Win32 API getenv()
#include <windows.h> // Get Absolute Path by Win32 API

std::string GET_WORKING_PATH_WIN32() {
  char working_directory[MAX_PATH + 1];
  GetCurrentDirectoryA(sizeof(working_directory),
                       working_directory); // **** win32 specific ****
  return working_directory;
}

#elif __APPLE__

#include <unistd.h>
#define GetCurrentDir getcwd

#else

#include <unistd.h>
#define GetCurrentDir getcwd

#endif

std::string GET_WORKING_PATH();

std::string GET_PATH_WITHOUT_FILE(std::string PATH);

auto IS_PATH(std::string PATH_OR_FILE) -> bool;
std::string GET_PATH_WITHOUT_LAST_SEPARATION(std::string PATH);
auto Temp_File_Rand() -> int;
auto CHECK_FILE_EXISTE(std::string PATH) -> bool;
auto CHECK_SETUP() -> bool;

#endif // GENERAL_SETUP_H
