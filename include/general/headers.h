// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#ifndef HEADERS_H
#define HEADERS_H

#include "class_token.h"

void parser_NewWindowWeb(std::string Token[2048], CLASS_TOKEN *o_tokens);

void AlifLexerParser(std::string FILE_NAME, std::string FILE_TYPE,
                     bool FIRST_FILE, bool TOKENS_ARE_PREDININED);

#endif