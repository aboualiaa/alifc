//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_CLASS_TOKEN_H
#define ALIFC_CLASS_TOKEN_H

#include <map>
#include <string>

using namespace std;

class CLASS_TOKEN {
public:
  // ----------------------------------
  // Script Type
  // ----------------------------------

  // to block setting Alif-Window inside librarys
  string ALIF_SCRIPT_TYPE;

  // ----------------------------------
  // File Path
  // ----------------------------------

  // usr/username/Desktop/myproject/src/mysource.alif
  // Used only by Lexer()
  string PATH_FULL_SOURCE;

  // ----------------------------------
  // Tokens
  // ----------------------------------

  string REAL_LINE[2048]; // The real Alif script line, without toknonisation !
  std::map<std::pair<int, int>, int>
      REAL_TOKEN_POSITION; // The real Alif script token position in real line !
  // [Line Number, Token Number] = "real char number"

  bool TOKENS_PREDEFINED = false;

  std::map<std::pair<int, int>, string>
      TOKEN; // TOKEN [Line Number, Token Number] = "token"

  int TOTAL[2048];
  int TOTAL_LINES;
  int NUMBER;
  int Line;

  // ----------------------------------
  // Constructor
  // ----------------------------------

  CLASS_TOKEN() {
    TOTAL_LINES = 1;
    NUMBER = 1;
    Line = 1;
    ALIF_SCRIPT_TYPE = "";
    PATH_FULL_SOURCE = "";
  }
};

#endif // ALIFC_CLASS_TOKEN_H
