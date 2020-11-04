//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef PARSER_CONTROL_H
#define PARSER_CONTROL_H

#define UNICODE
#define _UNICODE

#include <core/core.h>
#include <general/class_token.h>
#include <general/global.h>
#include <general/log.h>
#include <generator/generator.h>
#include <generator/pc_gui.h>
#include <string>

void parser_Control(std::string Token[2048], CLASS_TOKEN *o_tokens);

#endif // PARSER_CONTROL_H
