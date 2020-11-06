//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef GENERAL_CLASS_TOKEN_H
#define GENERAL_CLASS_TOKEN_H

#include <map>
#include <string>

namespace alif::lexer {

class Token {
public:
  // ----------------------------------
  // Script Type
  // ----------------------------------

  // to block setting Alif-Window inside librarys
  std::string ALIF_SCRIPT_TYPE;

  // ----------------------------------
  // File Path
  // ----------------------------------

  // usr/username/Desktop/myproject/src/mysource.alif
  // Used only by Lexer()
  std::string PATH_FULL_SOURCE;

  // ----------------------------------
  // Tokens
  // ----------------------------------

  std::string
      REAL_LINE[2048]; // The real Alif script line, without toknonisation !
  std::map<std::pair<int, int>, int>
      REAL_TOKEN_POSITION; // The real Alif script token position in real line !
  // [Line Number,lex::TokenNumber] = "real char number"

  bool TOKENS_PREDEFINED = false;

  std::map<std::pair<int, int>, std::string>
      TOKEN; // TOKEN [Line Number,lex::TokenNumber] = "token"

  int TOTAL[2048];
  int TOTAL_LINES;
  int NUMBER;
  int Line;

  // ----------------------------------
  // Constructor
  // ----------------------------------

  Token() {
    TOTAL_LINES = 1;
    NUMBER = 1;
    Line = 1;
    ALIF_SCRIPT_TYPE = "";
    PATH_FULL_SOURCE = "";
  }
};

} // namespace alif::lexer

#endif // GENERAL_CLASS_TOKEN_H
