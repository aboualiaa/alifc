// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#include <fstream>
#include <iostream>
#include <string>

#include <boost/lexical_cast.hpp>

#include "general/global.h"
#include "general/log.h"

void ALIF_ERROR(const std::string &ERROR_DESCRIPTION) {
  std::cout << std::endl << ERROR_DESCRIPTION << std::endl << std::endl;

  std::ofstream file;

  file.open(PATH_FULL_LOG, std::ios::app);

  file << ERROR_DESCRIPTION;

  file.close();

  exit(EXIT_FAILURE);
}

void DEBUG_MESSAGE(const std::string &MESSAGE, lex::Token * /*o_tokens*/) {
  LOG_MESSAGE_FULL.append(MESSAGE);

  if (DEBUG_PRINT_ON_SCREEN) {
    std::cout << MESSAGE;
  }
}

void LogMessage(const std::string &MESSAGE) {
  LOG_MESSAGE_FULL.append(MESSAGE);

  if (DEBUG_PRINT_ON_SCREEN) {
    std::cout << MESSAGE;
  }
}

void PATH_FULL_LOG_SAVE() {
  std::ofstream file;

  file.open(PATH_FULL_LOG);
  file << LOG_MESSAGE_FULL;
  file.close();
}

void ErrorCode(const std::string &ERROR_DESCRIPTION, lex::Token *o_tokens) {

  if (DEBUG) {
    DEBUG_MESSAGE("\n ----------- DEBUGING ERROR ------------- \n", o_tokens);
  }

  if (DEBUG) {
    DEBUG_MESSAGE("Class : " + TheClass + " \n", o_tokens);
  }
  if (DEBUG) {
    DEBUG_MESSAGE("Win : " + TheWindow + " \n", o_tokens);
  }
  if (DEBUG) {
    DEBUG_MESSAGE("Fun : " + TheFunction + " \n\n", o_tokens);
  }

  std::string ERR_MSG;

  if (SHOW_FILE_AND_LINE) {
    ERR_MSG = " الملف		: " + o_tokens->PATH_FULL_SOURCE + "\n";

    if (o_tokens->Line > 0) {
      ERR_MSG.append(" السطر		: " +
                     (boost::lexical_cast<std::string>(o_tokens->Line)) + "\n");
    }
  }

  ERR_MSG.append("\n الخطأ		: " + ERROR_DESCRIPTION);

  if (ERROR_PRINT_ON_SCREEN) {
    std::cout << "---| DEBUG_MESSAGE |--------------" << std::endl
              << ERR_MSG << std::endl
              << "------------------------" << std::endl;
  }

  LOG_MESSAGE_FULL.append(ERR_MSG);

  PATH_FULL_LOG_SAVE();

  // Exit code must be 'success', to let IDE read from DEBUG_MESSAGE file
  // if exit_failur, so IDE read data from process output
  exit(EXIT_SUCCESS);
}
