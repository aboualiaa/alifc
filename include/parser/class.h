//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef PARSER_CLASS_H
#define PARSER_CLASS_H

#define UNICODE
#define _UNICODE

#include <core/core.h>
#include <general/class_token.h>
#include <general/global.h>
#include <general/log.h>
#include <generator/generator.h>
#include <string>

// ----------------------------------

void parser_Class(std::string Token[2048], lex::Token *o_tokens);

#endif // PARSER_CLASS_H
