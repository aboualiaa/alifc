//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_COMPILE_H
#define ALIFC_COMPILE_H

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

// ------------------------------------------------
// Alif Compiler For Windows
// ------------------------------------------------

#include "win32.h" // GCC Compiler in Windows

#elif __APPLE__

// ------------------------------------------------
// Alif Compiler For Mac OS X
// ------------------------------------------------

#include "macos.h" // GCC Compiler in Mac OS X

#else

// ------------------------------------------------
// Alif Compiler For Linux
// ------------------------------------------------

#include "linux.h" // GCC Compiler in Linux

#endif

#endif // ALIFC_COMPILE_H
