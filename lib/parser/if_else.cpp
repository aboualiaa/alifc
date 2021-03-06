// ==================================
// (C)2019 DRAGA Hassan.
// 	www.aliflang.org
// ----------------------------------
// Alif Programming Language
//
// ==================================
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

void parser_IfElse(std::string Token[2048], lex::Token *o_tokens) {
  // وإلا

  if (!o_tokens->TOKENS_PREDEFINED) {
    return; // continue;
  }

  if (!IsInsideFunction) {
    ErrorCode("يجب استعمال الشرط داخل دالة", o_tokens);
  }

  if (ALIF_IF_STATUS < 1) {
    ErrorCode("لايمكن إستعمال ' وإلا ' من دون فتح شرط، ربمى تقصد ' إذا ' ",
              o_tokens);
  }

  if (Token[2] == "إذا") {
    ErrorCode("شرط غير صحيح، هل تقصد ' أو إذا ' ؟ ", o_tokens);
  }

  if (!Token[2].empty()) {
    ErrorCode(
        "أمر غير معروف : ' " + Token[2] +
            " '، على العموم إذا كنت تقصد شرط جديد المرجو إستعمال ' إذا ' ",
        o_tokens);
  }

  if (DEBUG) {
    DEBUG_MESSAGE("	[ELSE " + IntToString(ALIF_IF_STATUS) + "] \n\n",
                  o_tokens); // DEBUG
  }

  // TODO(aboualiaa): show error when double Else
  // if ...
  // else ...
  // else ...
  // end if

  // *** Generate Code ***
  if (!IsInsideWindow) {
    // Global Fun IF
    CPP_GLOBAL_FUN.append("\n } else { \n ");
  } else {
    // Local Fun IF
    cpp_AddScript(TheFunction, "\n } else { \n ");
  }
  // *** *** *** *** *** ***

  // continue;
}
