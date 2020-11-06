// ==================================
// (C)2020 DRAGA Hassan.
// 	 	www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// The Alif Programming Language
// ==================================

#define UNICODE
#define _UNICODE

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "compile/macos.h"
#include "core/core.h"
#include "general/global.h"
#include "general/headers.h"
#include "general/setup.h"
#include "generator/generator.h"
#include "generator/pc_gui.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "support/CommandLine.h"
#include "utf8/utf8.h"

namespace cli = alif::support::cli;
struct ALIFARGS : cli::CMDARGS {
public:
  explicit ALIFARGS(std::vector<char const *> args)
      : cli::CMDARGS(std::move(args)){};
  std::string input{};
  std::string output{};
  std::string logfile{};
  std::string workpath{};
  bool printlog{false};
};

static auto good_cmdline_args(ALIFARGS *cmdargs, cli::ENV *env) noexcept
    -> std::string;

auto main(int argc, char **argv) -> int {

  std::vector<char const *> args(argv, argv + argc);
  static auto err_logger = spdlog::stderr_color_mt("alifc");
  spdlog::set_level(spdlog::level::warn);
  auto env = cli::ENV();
  auto cmdargs = ALIFARGS(args);
  auto msg = good_cmdline_args(&cmdargs, &env);
  if (!msg.empty()) {
    spdlog::get("alifc")->critical(msg);
    return 1;
  }

  // setlocale(LC_ALL, "en_US.UTF-8");
  setlocale(LC_ALL, "ar_SA.UTF-8");

  std::string ARG_BUFFER;

  // check -o, -m32, -m64, -silent, -path=".." ...

  // alif  [source] [output] [logfile]
  PATH_FULL_ALIF = cmdargs.input;
  PATH_FULL_BIN = cmdargs.output;
  PATH_FULL_LOG = cmdargs.logfile;

  // ------------------------------------------------------
  // Check Files extention
  // ------------------------------------------------------

  if (PATH_FULL_ALIF.substr(PATH_FULL_ALIF.find_last_of('.') + 1,
                            std::string::npos) == "alifc") {
    THIS_IS_ALIF_C_FILE = true;
  } else if (PATH_FULL_ALIF.substr(PATH_FULL_ALIF.find_last_of('.') + 1,
                                   std::string::npos) != "alif") {
    ALIF_ERROR("Unsupported file extention : ' " + PATH_FULL_ALIF + " ' ");
    exit(EXIT_FAILURE);
  }

  // ------------------------------------------------------
  // Check Setup Installation
  // ------------------------------------------------------

  if (!CHECK_SETUP()) {
    ALIF_ERROR("Please re-install Alif Compiler, or download the latest "
               "version from \n\nwww.aliflang.org");
    exit(EXIT_FAILURE);
  }

  // ------------------------------------------------------
  // Alif Library
  // ------------------------------------------------------

  if (THIS_IS_ALIF_C_FILE) {
    // This is C++ pure file
    // there no Alif Source code
    // so, we must call compile method directly

    std::ifstream src(PATH_FULL_ALIF, std::ios::binary);
    std::ofstream dst(PATH_FULL_CPP, std::ios::binary);
    dst << src.rdbuf();

    // PATH_FULL_CPP = working_directory + PATH_FULL_ALIF; // This is more
    // quickly than copy files ! boost::filesystem::copy_file(PATH_FULL_ALIF,
    // PATH_FULL_CPP, boost::filesystem::copy_option::overwrite_if_exists);
  } else {
    // This is Alif Source Code

    // ------------------------------------------------------
    // Alif Lib Setting (to fix arab file name problem)
    // ------------------------------------------------------

    // TODO(aboualiaa): doesn't make any sense, uncomment if necessary
    // ALIF_LIB_SETTING();

    // ------------------------------------------------------
    // CPP CODE INITIALIZATION
    // ------------------------------------------------------

    // Set basic value to variables
    // to run a minimal app (Title, With, Heint, WebUI..)
    CG_INITIALIZATION();

    // ------------------------------------------------------
    // ALIF VARIABLES INITIALIZATION
    // ------------------------------------------------------

    // Set Initialisation of general alif variables..
    // Main window set, alif flag, inside fun or win..
    ALIF_VAR_INITIALIZATION_FOR_NEW_SOURCE_FILE(true);

    // ------------------------------------------------------
    // The Alif Standard Library
    // ------------------------------------------------------

    if (DEBUG) {
      LogMessage("\n ----------- The Alif Standard Library ------------- \n");
    }

    // FIXME(aboualiaa): also senseless
    // AlifLexerParser("alifstandardlib", "ALIFLIB", false,
    //                    false); // Global Tokens Predefinition.
    // AlifLexerParser("alifstandardlib", "ALIFLIB", false,
    //                true); // Full Syntaxt Checking.

    if (DEBUG) {
      LogMessage("\n ----------- Standard Library FINISH --------------- \n");
    }

    // ------------------------------------------------------
    // Lexer / Parcer for User source code
    // ------------------------------------------------------

    // Read source file..
    // LEXER	:	Create a list of tokens
    // PARSER	:	Read list of tokens, Generate a C++ code

    AlifLexerParser(PATH_FULL_ALIF, "ALIF", true, false);
  }

  // ------------------------------------------------------
  // Check if App Runing
  // ------------------------------------------------------

#ifdef _WIN32

  std::string CLEAR_BIN_CMD =
      string("@echo off & del /s \"") + PATH_FULL_BIN + string("\" >nul 2>&1");

  if (system(CLEAR_BIN_CMD.c_str()) != 0) {
    std::cout << endl
              << "Warning: Can't execut Windows remove EXE output command"
              << std::endl;
  }

  // boost::filesystem::remove(PATH_FULL_BIN);
  // std::remove(PATH_FULL_BIN);

#elif __APPLE__

  std::string CLEAR_BIN_CMD =
      std::string("rm -rf \"") + PATH_FULL_BIN + std::string("\" 2> /dev/null");

  if (system(CLEAR_BIN_CMD.c_str()) != 0) {
    std::cout << std::endl
              << "Warning: Can't execut macOS remove App output command"
              << std::endl;
  }

#else

  string CLEAR_BIN_CMD =
      string("rm -f \"") + PATH_FULL_BIN + string("\" 2> /dev/null");

  if (system(CLEAR_BIN_CMD.c_str()) != 0) {
    std::cout << endl
              << "Warning: Can't execut Linux remove Bin output command"
              << std::endl;
  }

#endif

#ifdef __APPLE__
  if (file_exists(PATH_FULL_BIN + "/Contents/MacOS/alif"))
#else
  if (CHECK_FILE_EXISTE(PATH_FULL_BIN))
#endif
  {
    ALIF_ERROR("\nأسف، لم تنجح عملية مسح هدا الملف، جرب غلق التطبيق: " +
               PATH_FULL_BIN);
    exit(EXIT_FAILURE);
  }

  // ------------------------------------------------------
  // Save debug message
  // ------------------------------------------------------

  if (!THIS_IS_ALIF_C_FILE) {
    if (DEBUG) {
      PATH_FULL_LOG_SAVE();
    }
  }

  // ++++++++
  // Debug
  // PATH_FULL_LOG_SAVE();
  // ALIF_ERROR("Compiling... ");
  // exit(EXIT_SUCCESS);
  // ++++++++

#ifdef _WIN32
  // ======================================================

  if (!THIS_IS_ALIF_C_FILE) {
    // Get GENERATED C++ CODE

    ofstream FILE_CPP;
    FILE_CPP.open(PATH_FULL_CPP); // .c_str());

    if (!FILE_CPP.is_open()) {
      ALIF_ERROR("ERROR: Could not create CPP temp file. " + PATH_FULL_CPP);
      exit(EXIT_FAILURE);
    }

    FILE_CPP << CODE_GENERATOR_GET_PC_GUI();
    FILE_CPP.close();
  }

  // app icon
  if (!PATH_FULL_ICO.empty())
    boost::replace_all(PATH_FULL_ICO, "\\", "\\\\");

  // GENERATE Windows Resource CODE
  ofstream FILE_RESOURCE;
  FILE_RESOURCE.open(PATH_FULL_RC); // .c_str());
  if (!FILE_RESOURCE.is_open()) {
    ALIF_ERROR("ERROR: Could not create RC temp files. ");
    exit(EXIT_FAILURE);
  }
  FILE_RESOURCE << "#include <wx/msw/wx.rc> \n";
  FILE_RESOURCE << "aaaa ICON \"" + PATH_FULL_ICO + "\"";
  FILE_RESOURCE.close();

  // Compile
  COMPILE_WIN_32BIT();

  // ======================================================

#elif __APPLE__

  // app icon
  if (!PATH_FULL_ICO.empty()) {
    boost::replace_all(PATH_FULL_ICO, "\\", "\\\\");
  }

  if (!THIS_IS_ALIF_C_FILE) {
    // GENERATE C++ CODE

    std::ofstream FILE_CPP;
    FILE_CPP.open(PATH_FULL_CPP, std::ios_base::out); // .c_str());
    if (!FILE_CPP.is_open()) {
      ALIF_ERROR("ERROR [F004]: Could not create CPP temp files. ");
      exit(EXIT_FAILURE);
    }
    FILE_CPP << CODE_GENERATOR_GET_PC_GUI();
    FILE_CPP.close();
  }

  // Compile
  COMPILE_MAC_64BIT();

  // ======================================================

#else // Linux

  if (!THIS_IS_ALIF_C_FILE) {
    // GENERATE C++ CODE

    ofstream FILE_CPP;
    FILE_CPP.open(PATH_FULL_CPP); // .c_str());
    if (!FILE_CPP.is_open()) {
      ALIF_ERROR("ERROR [F004]: Could not create CPP temp files. ");
      exit(EXIT_FAILURE);
    }
    FILE_CPP << CODE_GENERATOR_GET_PC_GUI();
    FILE_CPP.close();
  }

  // Compile
  COMPILE_LINUX_64BIT();

  // ======================================================

#endif

  // Hamdo li ALLAH =)
  exit(EXIT_SUCCESS);
}

/// \brief initialize options description and save values in cmdargs
/// \param desc holds description of supported args
/// \param cmdargs holds the actual args
void initArgDesc(boost::program_options::options_description *desc,
                 ALIFARGS *cmdargs, cli::ENV *env) {

  namespace po = boost::program_options;

  desc->add_options()

      ("help,h",

       po::bool_switch() //
           ->notifier([desc, env](auto v) {
             if (v) {
               print_help(*desc, env);
               exit(0);
             }
           }),

       "print out information on how to use this program and exit")

      //

      ("version,v",

       po::bool_switch() //
           ->notifier([](auto v) {
             if (v) {
               cli::print_version();
               exit(0);
             }
           }),

       "print out version and exit")

      //

      ("all-info",

       po::bool_switch() //
           ->notifier([env, desc](auto v) {
             if (v) {
               print_help(*desc, env);
               cli::print_version();
               exit(0);
             }
           }),

       "print out all info and exit")

      //

      ("usage,u",

       po::bool_switch() //
           ->notifier([env, desc](auto v) {
             if (v) {
               print_usage(*desc, env);
               exit(0);
             }
           }),

       "print usage and exit")

      //

      ("log,l",

       po::bool_switch(&cmdargs->printlog) //
           ->notifier([](auto v) {
             if (v) {
               spdlog::set_level(spdlog::level::debug);
               ERROR_PRINT_ON_SCREEN = true;
             }
           }),

       "turn on logging")

      //

      ("input,i", po::value(&cmdargs->input)->required(), "input")

      //

      ("output,o", po::value(&cmdargs->output), "output")

      //

      ("logfile", po::value(&cmdargs->logfile), "logfile")

      //

      ("workpath",
       po::value(&cmdargs->workpath) //
           ->notifier([](auto v) {
             working_directory = GET_PATH_WITHOUT_LAST_SEPARATION(v);
           }),
       "workpath")
      //

      ("beta",
       po::bool_switch() //
           ->notifier([](auto v) {
             if (v) {
               DEBUG = true;
             }
           }),
       "beta");
}

/// \brief does the housekeeping, use this to parse command lines,
///  do sanity and inconsistency checks, read files etc. After that
///  just start directly with your porgram logic
/// \param cmdargs struct to hold values of parsed args
/// \param env holds the vcid string
/// \return true if all logic is ok, false otherwise
static auto good_cmdline_args(ALIFARGS *cmdargs, cli::ENV *env) noexcept
    -> std::string {

  namespace po = boost::program_options;

  try {
    po::options_description desc(
        "\nUsage: alifc [options] <input> <output>\n\nAvailable Options");

    po::positional_options_description pos_desc;

    pos_desc.add("input", -1).add("output", 1);

    po::variables_map vm;
    initArgDesc(&desc, cmdargs, env);
    auto *av = cmdargs->get_raw_array();
    auto ac = static_cast<int>(cmdargs->get_raw_size());

    if (ac == 1) {
      print_usage(desc, env);
      return "Not enough arguments.";
    }

    auto parsed_opts = po::command_line_parser(ac, av)
                           .options(desc)
                           .positional(pos_desc)
                           .style(cli::po_style)
                           .run();

    po::store(parsed_opts, vm, true);

    po::notify(vm);

    // only after notifying vm, because the notifiers add these conflicts and/or
    // dependencies
    cmdargs->check_conflicts(vm);
    cmdargs->check_dependencies(vm);

  } catch (std::exception const &e) {
    std::string msg{e.what()};
    return msg;
  }

  return "";
}