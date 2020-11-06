//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include <string>

#include "general/class_token.h"

void ALIF_VAR_INITIALIZATION_FOR_NEW_SOURCE_FILE(bool FIRST_FILE);
void ALIF_LIB_SETTING();
void ADD_TOKEN(std::string TOKEN_CHAR, bool NEW_TOKEN, bool NEW_TOKEN_AFTER,
               int REAL_CHAR_NUMBER, CLASS_TOKEN *o_tokens);
void AlifLexerParser(std::string FILE_NAME, std::string FILE_TYPE,
                     bool FIRST_FILE, bool TOKENS_ARE_PREDININED);
#endif // LEXER_LEXER_H
