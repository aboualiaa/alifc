//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_LOG_H
#define ALIFC_LOG_H

#include <fstream>
#include <iostream>
#include <string>

#include "class_token.h"

// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

void ALIF_ERROR(std::string ERROR_DESCRIPTION);
void DEBUG_MESSAGE(std::string MESSAGE, CLASS_TOKEN *o_tokens);
void LogMessage(std::string MESSAGE);
void PATH_FULL_LOG_SAVE();
void ErrorCode(std::string ERROR_DESCRIPTION, CLASS_TOKEN *o_tokens);

#endif // ALIFC_LOG_H
