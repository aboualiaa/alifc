//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef PARSER_WINDOW_H
#define PARSER_WINDOW_H

std::string GetFormatedHTML(std::string HTML, std::string WindowName,
                            CLASS_TOKEN *o_tokens);
void HTML_to_c(std::string sHTMLPath, std::string sCPath, std::string VarName,
               std::string WindowName, CLASS_TOKEN *o_tokens);

void parser_NewWindowWeb(std::string Token[2048], CLASS_TOKEN *o_tokens);

void parser_NewWindow(std::string Token[2048], CLASS_TOKEN *o_tokens);

#endif // PARSER_WINDOW_H
