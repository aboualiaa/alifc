//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef PARSER_BOOL_H
#define PARSER_BOOL_H

#define UNICODE
#define _UNICODE

#include <core/core.h>
#include <general/class_token.h>
#include <general/global.h>
#include <general/log.h>
#include <generator/generator.h>
#include <generator/pc_gui.h>
#include <string>

// ----------------------------------

void parser_bool(std::string Token[2048], lex::Token *o_tokens);

#endif // PARSER_BOOL_H
