//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef GENERAL_LOG_H
#define GENERAL_LOG_H

#include <fstream>
#include <iostream>
#include <string>

#include "class_token.h"

namespace lex = alif::lexer;

void ALIF_ERROR(const std::string &ERROR_DESCRIPTION);
void DEBUG_MESSAGE(const std::string &MESSAGE, lex::Token *o_tokens);
void LogMessage(const std::string &MESSAGE);
void PATH_FULL_LOG_SAVE();
void ErrorCode(const std::string &ERROR_DESCRIPTION, lex::Token *o_tokens);

#endif // GENERAL_LOG_H
