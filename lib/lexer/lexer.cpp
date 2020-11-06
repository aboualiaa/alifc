// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#include <algorithm>
#include <fstream>

#include "core/core.h"
#include "general/global.h"
#include "general/log.h"
#include "general/setup.h"
#include "parser/parser.h"

namespace lex = alif::lexer;

void ALIF_VAR_INITIALIZATION_FOR_NEW_SOURCE_FILE(bool FIRST_FILE) {
  // ----------------------------------
  // نافدة
  // ----------------------------------

  if (FIRST_FILE) {
    MAIN_WIN_IS_SET = false;
    MAIN_WIN_AT_LINE = "0";
  }

  IsInsideWindow = false;
  TheWindow = "";

  // ----------------------------------
  // دالة
  // ----------------------------------

  IsInsideFunction = false;
  TheFunction = "";

  // ----------------------------------
  // PARENTHESIS / IF
  // ----------------------------------

  ALIF_PARENTHESIS_STATUS = 0;
  ALIF_IF_STATUS = 0;

  // ----------------------------------
  // Code
  // ----------------------------------

  ScriptSyntaxBuffer = "";
  ScriptBuffer = "";
}

void ALIF_LIB_SETTING() {
  std::ifstream FILE_STREAM(PATH_FULL_LIB_SETTING.c_str());

  if (!FILE_STREAM.is_open()) {
    ALIF_ERROR("ERROR [F001]: Could not open " + PATH_FULL_LIB_SETTING);
    exit(EXIT_FAILURE);
  }

  std::string LINE8;

  while (getline(FILE_STREAM, LINE8)) {
    // ------------------------------------------------------
    // Ignore blank lines
    // ------------------------------------------------------

    if ((LINE8 == "\n") || (LINE8 == "\r") || (LINE8 == "\r\n") ||
        (LINE8.empty()) || (LINE8 == " ")) {
      continue;
    }

    // ------------------------------------------------------
    // Remove bad line-break character
    // Windows: \r\n
    // Linux: \n
    // MacOS: \r
    // ------------------------------------------------------

    size_t LINE_FIX_LAST_POS = LINE8.find_last_not_of("\r\n");

    if (LINE_FIX_LAST_POS != std::string::npos) {
      LINE8.substr(0, LINE_FIX_LAST_POS + 1).swap(LINE8);
    }

    // ------------------------------------------------------
    // Remove extra spaces
    // ------------------------------------------------------

    // LINE8 = REMOVE_DOUBLE_SPACE(LINE8, &OBJ_CLASS_TOKEN);

    // if ((LINE8 == "\n") || (LINE8 == "\r") || (LINE8 == "\r\n") || (LINE8 ==
    // "") || (LINE8 == " ")) continue;

    // ------------------------------------------------------
    // Split
    // ------------------------------------------------------

    // رسالة|risalah

    LIB_FILE_NAME[LINE8.substr(0, LINE8.find('|'))] =
        LINE8.substr(LINE8.find('|') + 1);
  }

  FILE_STREAM.close();
}

void ADD_TOKEN(const std::string &TOKEN_CHAR, bool NEW_TOKEN,
               bool NEW_TOKEN_AFTER, int REAL_CHAR_NUMBER,
               lex::Token *o_tokens) {
  if (NEW_TOKEN) {
    // New Token
    if (!o_tokens
             ->TOKEN[std::make_pair(o_tokens->TOTAL_LINES,
                                    o_tokens->TOTAL[o_tokens->TOTAL_LINES])]
             .empty()) {
      o_tokens->TOTAL[o_tokens->TOTAL_LINES]++;
    }

    if (!TOKEN_CHAR.empty()) {
      if (o_tokens->TOTAL[o_tokens->TOTAL_LINES] < 1) {
        o_tokens->TOTAL[o_tokens->TOTAL_LINES] = 1;
      }

      o_tokens->TOKEN[std::make_pair(o_tokens->TOTAL_LINES,
                                     o_tokens->TOTAL[o_tokens->TOTAL_LINES])] =
          TOKEN_CHAR;

      // Set Reallex::Tokenposition in the real line
      o_tokens->REAL_TOKEN_POSITION[std::make_pair(
          o_tokens->TOTAL_LINES, o_tokens->TOTAL[o_tokens->TOTAL_LINES])] =
          REAL_CHAR_NUMBER + CharCount_utf8(TOKEN_CHAR, o_tokens);

      if (NEW_TOKEN_AFTER &&
          !o_tokens
               ->TOKEN[std::make_pair(o_tokens->TOTAL_LINES,
                                      o_tokens->TOTAL[o_tokens->TOTAL_LINES])]
               .empty()) {
        o_tokens->TOTAL[o_tokens->TOTAL_LINES]++;
      }
    }
  } else if (!TOKEN_CHAR.empty()) {
    // New Char
    if (o_tokens->TOTAL[o_tokens->TOTAL_LINES] < 1) {
      o_tokens->TOTAL[o_tokens->TOTAL_LINES] = 1;
    }

    (o_tokens->TOKEN[std::make_pair(o_tokens->TOTAL_LINES,
                                    o_tokens->TOTAL[o_tokens->TOTAL_LINES])])
        .append(TOKEN_CHAR);

    // Set Reallex::Tokenposition in the real line
    o_tokens->REAL_TOKEN_POSITION[std::make_pair(
        o_tokens->TOTAL_LINES, o_tokens->TOTAL[o_tokens->TOTAL_LINES])] =
        REAL_CHAR_NUMBER + CharCount_utf8(TOKEN_CHAR, o_tokens);

    if (NEW_TOKEN_AFTER &&
        !o_tokens
             ->TOKEN[std::make_pair(o_tokens->TOTAL_LINES,
                                    o_tokens->TOTAL[o_tokens->TOTAL_LINES])]
             .empty()) {
      o_tokens->TOTAL[o_tokens->TOTAL_LINES]++;
    }
  }
}

void AlifLexerParser(std::string fileName, const std::string &fileType,
                     bool isFirstFile, bool tokensArePredefined) {

  lex::Token token;

  std::string lower_file_type{fileType};
  std::transform(lower_file_type.begin(), lower_file_type.end(),
                 lower_file_type.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  std::string lower_file_name{fileName};
  std::transform(lower_file_name.begin(), lower_file_name.end(),
                 lower_file_name.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  // TODO(aboualiaa): check file_name format
  // check if file existe
  // if(!IsValidStringFormat(Token[4], o_tokens))
  // ErrorCode("خطأ في كتابة إسم الملف: "+ Token[4], o_tokens);

  int pos = lower_file_name.find_last_of('.');
  std::string file_extension;

  // Get extention
  if (pos > 0) {
    file_extension = lower_file_name.substr(pos + 1);
    if (file_extension != lower_file_type) {
      // TODO(aboualiaa): or if it is not one of alif, alifui, alifuiw, aliflib
      ErrorCode("علة: نوع ملف غير معروف : ' " + fileType + " ' ", &token);
    }
  } else {
    lower_file_name.append(".").append(lower_file_type);
  }

  if (IS_PATH(lower_file_name)) {
    token.PATH_FULL_SOURCE = lower_file_name;
    if (lower_file_type == "alifuiw") {
      PATH_FULL_WINDOW_WEB =
          working_directory + path_separator + lower_file_name;
      // We don't need to do anything with Alif WindowWeb just back to privious
      // parser to continue now, we have the full path of Alif WindowWeb file
      // PATH_FULL_WINDOW_WEB
      return;
    }
  } else {
    token.PATH_FULL_SOURCE =
        working_directory + path_separator + lower_file_name;
    if (lower_file_type == "alifuiw") {
      PATH_FULL_WINDOW_WEB =
          working_directory + path_separator + lower_file_name;
      return;
    }
  }

  if (lower_file_type == "aliflib") {
    ErrorCode("نأسف، حاليا مترجم ألف لا يقبل المكتبات الشخصية، أو مكتبات مسبقة "
              "الترجمة، المرجو إزالة إمتداد الملف من أجل إستعمال المكتبات "
              "المدمجة مع مترجم ألف : ' " +
                  fileName + " ' ",
              &token);
  }

  if (!file_exists(token.PATH_FULL_SOURCE)) {
    SHOW_FILE_AND_LINE = false;
    ErrorCode("ملف غير موجود : ' " + token.PATH_FULL_SOURCE + " ' ", &token);
  }

  // ------------------------------------------------------
  // Current File Type
  // ------------------------------------------------------

  token.ALIF_SCRIPT_TYPE = lower_file_type;

  // ------------------------------------------------------
  // ALIF VARIABLES INITIALIZATION
  // ------------------------------------------------------

  // Set Initialisation of general variables..
  // Main window set, flag, inside fun or win..
  ALIF_VAR_INITIALIZATION_FOR_NEW_SOURCE_FILE(isFirstFile);

  // ------------------------------------------------------
  // Read Source file (ANSI File name)
  // ------------------------------------------------------

  std::ifstream input_file(token.PATH_FULL_SOURCE);

  if (!input_file.is_open()) {
    ALIF_ERROR("ERROR [F001]: Could not open " + token.PATH_FULL_SOURCE);
    exit(EXIT_FAILURE);
  }

  // ------------------------------------------------------

  std::string LINE8;

  bool INSIDE_STRING_CPP = false;

  while (getline(input_file, LINE8)) {
    // ------------------------------------------------------
    // Ignore blank lines
    // ------------------------------------------------------

    if ((LINE8 == "\n") || (LINE8 == "\r") || (LINE8 == "\r\n") ||
        (LINE8.empty()) || (LINE8 == " ")) {
      token.TOTAL[token.TOTAL_LINES] = 0;
      token.TOTAL_LINES++;
      continue;
    }

    // ------------------------------------------------------
    // Remove bad line-break character
    // Windows: \r\n
    // Linux: \n
    // MacOS: \r
    // ------------------------------------------------------

    size_t LINE_FIX_LAST_POS = LINE8.find_last_not_of("\r\n");

    if (LINE_FIX_LAST_POS != std::string::npos) {
      LINE8.substr(0, LINE_FIX_LAST_POS + 1).swap(LINE8);
    }

    // ------------------------------------------------------
    // Remove extra spaces
    // ------------------------------------------------------

    LINE8 = REMOVE_DOUBLE_SPACE(LINE8, &token);

    if ((LINE8 == "\n") || (LINE8 == "\r") || (LINE8 == "\r\n") ||
        (LINE8.empty()) || (LINE8 == " ")) {
      token.TOTAL[token.TOTAL_LINES] = 0;
      token.TOTAL_LINES++;
      continue;
    }

    // Set Real Line
    token.REAL_LINE[token.TOTAL_LINES] = LINE8;

    // ------------------------------------------------------
    // Char loop
    // ------------------------------------------------------

    int CHAR_NUMBER = 0;
    int LINE_CHAR_TOTAL = 0;
    std::string Char;
    bool INSIDE_STRING = false;

    token.TOTAL[token.TOTAL_LINES] = 0;

    LINE_CHAR_TOTAL = CharCount_utf8(LINE8, &token);

    while (CHAR_NUMBER < LINE_CHAR_TOTAL) // '<=' is wrong!
    {
      Char = substr_utf8(LINE8, CHAR_NUMBER, 1);
      // ---------------------------------------------

      if (Char == "۰") {
        Char = "0";
      } else if (Char == "۱") {
        Char = "1";
      } else if (Char == "۲") {
        Char = "2";
      } else if (Char == "۳") {
        Char = "3";
      } else if (Char == "۴") {
        Char = "4";
      } else if (Char == "۵") {
        Char = "5";
      } else if (Char == "۶") {
        Char = "6";
      } else if (Char == "۷") {
        Char = "7";
      } else if (Char == "۸") {
        Char = "8";
      } else if (Char == "۹") {
        Char = "9";

      } else if (Char == "“") {
        Char = "\"";
      } else if (Char == "”") {
        Char = "\"";

      } else if (Char == "‘") {
        Char = "'";
      }

      // Comments
      // if ( (Char == "\\") && (substr_utf8(LINE8, (CHAR_NUMBER + 1), 1) ==
      // "\\") && !INSIDE_STRING)
      if ((CHAR_NUMBER == 0) && (Char == "'") && !INSIDE_STRING) // '
      {
        goto NEXT_LINE;
      }

      // -------------------------------------------------------------

      // _س_ / _ج_

      if ((Char == "_" && (substr_utf8(LINE8, CHAR_NUMBER + 1, 1) == "س") &&
           (substr_utf8(LINE8, CHAR_NUMBER + 2, 1) == "_")) ||
          (Char == "_" && (substr_utf8(LINE8, CHAR_NUMBER + 1, 1) == "ج") &&
           (substr_utf8(LINE8, CHAR_NUMBER + 2, 1) == "_")) ||
          (Char == "@" &&
           (substr_utf8(LINE8, CHAR_NUMBER + 1, 1) != "@"))) // Skip '@@'
      {
        std::string CompletChar;

        if (substr_utf8(LINE8, CHAR_NUMBER + 1, 1) == "س") {
          CompletChar = "_س_";
        } else if (substr_utf8(LINE8, CHAR_NUMBER + 1, 1) == "ج") {
          CompletChar = "_ج_";
        }

        if (Char != "@") {
          CHAR_NUMBER = CHAR_NUMBER + 2; // Point to after : _س_
        }

        if (!INSIDE_STRING_CPP) {
          if (Char != "@") {
            ADD_TOKEN(CompletChar, true, true, CHAR_NUMBER, &token);

            // if(DEBUG)DEBUG_MESSAGE(" <NEW start:_س_> " , &token);
            // // DEBUG
          } else {
            ADD_TOKEN("@", true, true, CHAR_NUMBER, &token);

            // if(DEBUG)DEBUG_MESSAGE(" <NEW start:@> " , &token); //
            // DEBUG
          }

          INSIDE_STRING_CPP = true;
          LIB_LEXER_CG_BUFER = "";
        } else {
          INSIDE_STRING_CPP = false;
          ADD_TOKEN(LIB_LEXER_CG_BUFER, true, true, CHAR_NUMBER, &token);

          if (Char != "@") {
            ADD_TOKEN(CompletChar, true, true, CHAR_NUMBER, &token);

            // if(DEBUG)DEBUG_MESSAGE(" <NEW END:_س_>|" + LIB_LEXER_CG_BUFER +
            // "| " , &token); // DEBUG
          } else {
            ADD_TOKEN("@", true, true, CHAR_NUMBER, &token);

            // if(DEBUG)DEBUG_MESSAGE(" <NEW END:@>|" + LIB_LEXER_CG_BUFER + "|
            // " , &token); // DEBUG
          }

          LIB_LEXER_CG_BUFER = "";
        }
      } else if (INSIDE_STRING_CPP) {
        // This char is inside quote _س_

        LIB_LEXER_CG_BUFER.append(Char);
      } else if ((Char == "'" && !INSIDE_STRING && !INSIDE_STRING_CPP) ||
                 (Char == "-" &&
                  substr_utf8(LINE8, CHAR_NUMBER + 1, 1) == "-" &&
                  !INSIDE_STRING && !INSIDE_STRING_CPP)) {
        goto NEXT_LINE;
      } else if (Char == "\"") {
        /*
        if (INSIDE_STRING_CPP)
        {
                // This char is inside quote _س_ ..... _س_
                // Add this char to this current token
                ADD_TOKEN("\"", false, false, CHAR_NUMBER, &token);
        }
        */
        if (INSIDE_STRING) {
          // String End
          // Add char, and new token after
          ADD_TOKEN("\"", false, true, CHAR_NUMBER, &token);
          INSIDE_STRING = false;
        } else {
          // String Start
          // New token, add char
          ADD_TOKEN("\"", true, false, CHAR_NUMBER, &token);
          INSIDE_STRING = true;
        }
      }
      /*
      else if (Char == "@")
      {
              if (INSIDE_STRING)
              {
                      // Inside String
                      // Add char, continue
                      ADD_TOKEN("@", false, false, CHAR_NUMBER,
      &token);
              }
              else
              {
                      // New token, add char
                      ADD_TOKEN("@", true, true, CHAR_NUMBER, &token);
              }
      }
      */
      else if (INSIDE_STRING) {
        // This char is inside quote " " OR _س_
        // Add this char to this current token
        ADD_TOKEN(Char, false, false, CHAR_NUMBER, &token);
      } else if (Char == " ") // Space
      {
        // ignore space!
        // Point to next token
        ADD_TOKEN("", true, false, CHAR_NUMBER, &token);
      } else if (Char == "-") // || Char == "+")
      {
        // If is '-123', must be in the same token
        // else, '-', and '123', in different token

        if (IsValidDigit(substr_utf8(LINE8, CHAR_NUMBER + 1, 1), false,
                         &token)) {
          // FORCED Point to next token
          // if(token.TOKEN[std::make_pair(token.TOTAL_LINES,
          // token.TOTAL[token.TOTAL_LINES])] != "")
          //{
          // token.TOTAL[token.TOTAL_LINES]++;
          //}

          // Add char '-', next is digit, so no new token
          ADD_TOKEN(Char, true, false, CHAR_NUMBER, &token);
        } else {
          // Add char
          // Point to next token
          ADD_TOKEN(Char, true, true, CHAR_NUMBER, &token);
        }
      } else if (Char == "@" || // C++ Code
                 Char == "#" || // Hash
                 Char == ":" || // Operator
                 Char == "=" || Char == "+" ||
                 // Char == "-" ||
                 Char == "*" || Char == "&" || // New line
                 Char == "(" || Char == ")" || Char == "[" || Char == "]" ||
                 Char == "{" || Char == "}" || Char == "!" || Char == "<" ||
                 Char == ">" || Char == ";" || // To show error !
                 Char == "،" ||                // اشارة ،
                 Char == ",") {
        // Add char
        // Point to next token
        ADD_TOKEN(Char, true, true, CHAR_NUMBER, &token);
      } else {
        // Add char
        ADD_TOKEN(Char, false, false, CHAR_NUMBER, &token);
      }
      // ======================================================
      CHAR_NUMBER++;
    } // End char loop.
  NEXT_LINE:

    if (INSIDE_STRING_CPP) {
      // ADD_TOKEN("\n", false, false, CHAR_NUMBER, &token);
      LIB_LEXER_CG_BUFER.append("\n");
    }

    token.TOTAL_LINES++;
  } // End Line loop.
  // ------------------------------------------------------

  if (isFirstFile) {
    // This is the first file (main.alif)
    // this file, need Tokens Predefinetion

    // ------------------------------------------------------
    // Parser - Tokens Predefinetion
    // ------------------------------------------------------
    if (DEBUG) {
      DEBUG_MESSAGE("\n --- TOKENS PREDEFINITION START --- \n", &token);
    }
    token.TOKENS_PREDEFINED = false;
    // Read list of tokens
    ALIF_PARSER(&token);
    if (DEBUG) {
      DEBUG_MESSAGE("\n --- TOKENS PREDEFINITION END --- \n\n", &token);
    }

    // ------------------------------------------------------
    // Parser - Normal way
    // ------------------------------------------------------
    if (DEBUG) {
      DEBUG_MESSAGE(" ----------- DEBUGING START ----------- \n", &token);
    }
    token.TOKENS_PREDEFINED = true;
    // Read list of tokens
    ALIF_PARSER(&token);
    // Check final application code
    FINAL_APPLICATION_CODE_CHECKING(&token, isFirstFile);
    if (DEBUG) {
      DEBUG_MESSAGE("\n ----------- DEBUGING FINISH ------------- \n", &token);
    }
  } else {
    // This is a seconde file (mylib.alif)
    // so, check if this file need Tokens Predefinetion

    if (!tokensArePredefined) {
      // This file did not have any Tokens Predefinetion
      // so, lets start one..

      // ------------------------------------------------------
      // Parser - Tokens Predefinetion
      // ------------------------------------------------------
      if (DEBUG) {
        DEBUG_MESSAGE("\n --- TOKENS PREDEFINITION START --- \n", &token);
      }
      token.TOKENS_PREDEFINED = false;
      // Read list of tokens
      ALIF_PARSER(&token);
      if (DEBUG) {
        DEBUG_MESSAGE("\n --- TOKENS PREDEFINITION END --- \n\n", &token);
      }
    } else {
      // This file have already Tokens Predefinetion
      // so, lets parse in normal way..

      // ------------------------------------------------------
      // Parser - Normal way
      // ------------------------------------------------------
      if (DEBUG) {
        DEBUG_MESSAGE(" ----------- DEBUGING START ----------- \n", &token);
      }
      token.TOKENS_PREDEFINED = true;
      // Read list of tokens
      ALIF_PARSER(&token);
      // Check final application code
      FINAL_APPLICATION_CODE_CHECKING(&token, isFirstFile);
      if (DEBUG) {
        DEBUG_MESSAGE("\n ----------- DEBUGING FINISH ------------- \n",
                      &token);
      }
    }
  }
}
