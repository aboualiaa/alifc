//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_WINDOW_H
#define ALIFC_WINDOW_H

std::string GetFormatedHTML(std::string HTML, std::string WindowName,
                            CLASS_TOKEN *o_tokens);

void HTML_to_c(string sHTMLPath, string sCPath, string VarName,
               string WindowName, CLASS_TOKEN *o_tokens);

void parser_NewWindowWeb(string Token[2048], CLASS_TOKEN *o_tokens);

void parser_NewWindow(string Token[2048], CLASS_TOKEN *o_tokens);

#endif // ALIFC_WINDOW_H
