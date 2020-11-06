// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#ifndef GENERAL_HEADERS_H
#define GENERAL_HEADERS_H

#include "class_token.h"

namespace lex = alif::lexer;

void parser_NewWindowWeb(std::string Token[2048], lex::Token *o_tokens);

void AlifLexerParser(std::string FILE_NAME, const std::string &FILE_TYPE,
                     bool FIRST_FILE, bool Tokens_Are_Predefined);

#endif