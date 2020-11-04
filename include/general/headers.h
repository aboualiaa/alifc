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

string CHECK_CALL_FUN_ARG(bool CALL_FUN_GLOBAL, string CALL_WIN_OR_CLASS,
                          string CALL_FUN, int CALL_IS_CLASS,
                          string FROM_WIN_OR_CLASS, string FROM_FUN,
                          string SYNTAX[2048], int SYNTAX_LONG,
                          CLASS_TOKEN *o_tokens);

void SetNewVar(bool IsGlobal, string TmpWindow, string TmpFunction,
               string VarName, string VarDataType, bool IsConstant,
               bool IsArray, int Line, CLASS_TOKEN *o_tokens);

void parser_NewWindowWeb(string Token[2048], CLASS_TOKEN *o_tokens);

void AlifLexerParser(string FILE_NAME, string FILE_TYPE, bool FIRST_FILE,
                     bool TOKENS_ARE_PREDININED);

#endif