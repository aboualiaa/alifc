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
#include <string>

#include "core/core.h"
#include "general/global.h"

#ifdef _WIN32

#include <direct.h> // getcwd (Get current working directory)
#define GetCurrentDir _getcwd

#include <string>
#include <windows.h> // Get Working Path by Win32 API

//#include <w32api.h>
//#include <Winbase.h>
#include <stdlib.h>  // Get Temp envirenemt by Win32 API getenv()
#include <windows.h> // Get Absolute Path by Win32 API

std::string GET_WORKING_PATH_WIN32() {
  char working_directory[MAX_PATH + 1];
  GetCurrentDirectoryA(sizeof(working_directory),
                       working_directory); // **** win32 specific ****
  return working_directory;
}

#elif __APPLE__

#include <unistd.h>
#define GetCurrentDir getcwd

#else

#include <unistd.h>
#define GetCurrentDir getcwd

#endif

auto GET_WORKING_PATH() -> std::string {
  // https://msdn.microsoft.com/en-us/library/sf98bd4y.aspx

  char *buffer = nullptr;

  if ((buffer = GetCurrentDir(nullptr, 0)) == nullptr) {
    return nullptr;
  } // printf( "%s \nLength: %d\n", buffer, strnlen(buffer) );
  // free(buffer);

  return buffer;
}

auto GET_PATH_WITHOUT_FILE(const std::string &PATH) -> std::string {
  // In: /abc/def/test.xx
  // Out: /abc/def/

#ifdef _WIN32
  int POSITION = PATH.find_last_of("\\/");
#else
  int POSITION = PATH.find_last_of("//");
#endif

  if (POSITION < 1) // To avoid ABC/DEF/ or Relative Path
  {
    return "";
  }
#ifdef _WIN32
  return PATH.substr(0, PATH.find_last_of("\\/"));
#else
  return PATH.substr(0, PATH.find_last_of("//"));
#endif
}

auto IS_PATH(const std::string &str) -> bool {
  // 'myfile.x'               --> false.
  // '/abc/test/myfile.x'     --> true.

  int pos = str.find_last_of(path_separator);

  return pos >= 0;
}

auto GET_PATH_WITHOUT_LAST_SEPARATION(std::string PATH) -> std::string {
  // In : '/abc/test/folder/'
  // Out : '/abc/test/folder'

  std::string Last_Char = PATH.substr(PATH.length() - 1); // PATH.back()

#ifdef _WIN32
  if (Last_Char == "\\")
    return PATH.substr(0, PATH.length() - 1);
  else
    return PATH;
#else
  if (Last_Char == "/") {
    return PATH.substr(0, PATH.length() - 1);
  } else {
    return PATH;
  }
#endif
}

auto Temp_File_Rand() -> int {
  srand(time(nullptr));
  return rand() % 10 + 1000;
}

/*
bool CHECK_FOLDER_EXISTE(string PATH)
{
        #ifdef _WIN32
                //
        #else
                struct stat info;

                if( stat( PATH, &info ) != 0 )
                        return false; // cannot access
                else if( info.st_mode & S_IFDIR )
                        return true; // is a directory
                else
                        return false; // is no directory
        #endif
}
*/

auto file_exists(const std::string str) -> bool {
  return std::filesystem::exists(str);
}

auto CHECK_SETUP() -> bool // string ARGV_0, string OUTPUT)
{
  if (DEBUG) {
    RANDOM = "0000";
  } else {
    RANDOM = IntToString(Temp_File_Rand());
  }

#ifdef _WIN32

  // -------------------
  // Get Absolute Path
  // -------------------

  TCHAR WIN32_PATH_BUFFER[MAX_PATH];

  if (!GetModuleFileNameW(NULL, WIN32_PATH_BUFFER, MAX_PATH)) {
    ALIF_ERROR(
        "Sorry, Can't get Absolut Path from Win API \n"
        "Please add the path where 'alif.exe' existe, for example : \n\n"
        "alif [source.alif] [output.exe] [logfile.txt] -workpath=C:\\Alif ");
  }

  wstring WIN32_PATH_BUFFER_W(&WIN32_PATH_BUFFER[0]);

  PATH_ABSOLUTE =
      string(WIN32_PATH_BUFFER_W.begin(), WIN32_PATH_BUFFER_W.end());

  PATH_ABSOLUTE = PATH_ABSOLUTE.substr(0, PATH_ABSOLUTE.find_last_of("\\/"));

  // -------------------
  // Get Working Path
  // -------------------

  if (working_directory.empty()) {
    working_directory = GET_WORKING_PATH_WIN32();

    if (working_directory == PATH_ABSOLUTE) {
      // Tray a seconde solution !
      working_directory = GET_PATH_WITHOUT_FILE(PATH_FULL_ALIF);
    }
  }

  // -------------------
  // Get Temp Path
  // -------------------

  // C:\Users\Me\AppData\Local\Temp

  ostringstream TEMP_BUFFER;
  TEMP_BUFFER << getenv("Temp");
  PATH_TEMP = TEMP_BUFFER.str();

  // -------------------
  // Other Path
  // -------------------

  PATH_FULL_GCC = PATH_ABSOLUTE + "\\bin\\g++.exe";
  PATH_FULL_CPP = PATH_TEMP + "\\alifcompiler_" + RANDOM + ".cpp";
  PATH_FULL_OBJ = PATH_TEMP + "\\alifcompiler_" + RANDOM + ".o";
  PATH_FULL_RC = PATH_TEMP + "\\alifcompiler_" + RANDOM + ".rc";
  PATH_FULL_ICO = PATH_ABSOLUTE + "\\alif.ico";

  PATH_FULL_LIB_SETTING = PATH_ABSOLUTE + "\\aliflib\\aliflib.inf";

#elif __APPLE__

  // Mac OS X

  // alif_1.0-1.pkg
  //		/usr/local/bin/alif
  //		/Library/Application
  // Support/Aliflang/Alif_Compiler/aliflib/aliflib.inf
  // /Library/Application Support/Aliflang/Alif_Compiler/linux_alif_version.inf
  // /Library/Application
  // Support/Aliflang/Alif_Compiler/Alif_Arabic_Programming_Language
  //		/Library/Application Support/Aliflang/Alif_Compiler/alif.icns
  //		/Library/Application Support/Aliflang/Alif_Compiler/Info.plist

  // aliflibwx_3.1-1.pkg
  //		/Library/Application
  // Support/Aliflang/Alif_Lib_WX/include/[wx][boost][utf8]
  // /Library/Application Support/Aliflang/Alif_Lib_WX/lib/[.a]
  // /Library/Application
  // Support/Aliflang/Alif_Lib_WX/linux_aliflibwx_version.inf

  // alifstudio_1.0-1.pkg
  //		/Applications/Alif Studio.app
  //		/Library/Application
  // Support/Aliflang/Alif_Studio/linux_alifstudio_version.inf
  //		/Library/Application Support/Aliflang/Alif_Studio/alifstudio.png
  //		/Library/Application Support/Aliflang/Alif_Studio/mupdate

  // -------------------
  // Get Absolute Path
  // -------------------

  PATH_ABSOLUTE = "/usr/local/bin";

  // -------------------
  // Get Working Path
  // -------------------

  if (working_directory.empty()) {
    working_directory = GET_WORKING_PATH();

    if (working_directory == PATH_ABSOLUTE) {
      // Tray a seconde solution !
      working_directory = GET_PATH_WITHOUT_FILE(PATH_FULL_ALIF);
    }
  }

  // -------------------
  // Get Temp Path
  // -------------------

  PATH_TEMP = "/tmp";

  // -------------------
  // Other Path
  // -------------------

  PATH_FULL_BIN_TMP = PATH_TEMP + "/alifcompiler_bin_" + RANDOM;

  PATH_FULL_GCC = "clang++";
  PATH_FULL_CPP = PATH_TEMP + "/alifcompiler_" + RANDOM + ".cpp";
  PATH_FULL_OBJ = PATH_TEMP + "/alifcompiler_" + RANDOM + ".o";
  PATH_FULL_RC = "";
  PATH_FULL_ICO =
      "/Library/Application Support/Aliflang/Alif_Compiler/alif.icns";

  PATH_FULL_LIB_SETTING =
      "/Library/Application Support/Aliflang/Alif_Compiler/aliflib/aliflib.inf";

  PATH_FULL_PLIST =
      "/Library/Application Support/Aliflang/Alif_Compiler/Info.plist";

#else

  // Linux

  // aliflang_1.0-1.deb
  //		/usr/local/bin/alif.bin
  //		/usr/local/lib/aliflib/aliflib.inf
  //		/usr/local/share/aliflang/copyright
  //		/usr/local/share/aliflang/linux_alif_version.inf
  //		/usr/local/share/aliflang/Alif_Arabic_Programming_Language

  // aliflibwx_3.1-1.deb
  //		/usr/local/include/aliflibwx/[wx][boost][utf8]
  //		/usr/local/lib/aliflibwx/[.a]
  //		/usr/local/share/aliflibwx/linux_aliflibwx_version.inf
  //		/usr/share/doc/aliflibwx/copyright (txt)

  // alifstudio_1.0-1.deb
  //		/usr/local/bin/alifstudio.bin
  //		/usr/local/bin/mupdate.bin
  //		/usr/local/share/alifstudio/copyright
  //		/usr/local/share/alifstudio/linux_alifstudio_version.inf
  //		/usr/share/alifstudio/alifstudio.ico
  //		/usr/share/alifstudio/alifstudio.png
  //		/usr/share/applications/'Alif Studio'

  // -------------------
  // Get Absolute Path
  // -------------------

  PATH_ABSOLUTE = "/usr/local/bin";

  // -------------------
  // Get Working Path
  // -------------------

  if (working_directory.empty()) {
    working_directory = GET_WORKING_PATH();

    if (working_directory == PATH_ABSOLUTE) {
      // Tray a seconde solution !
      working_directory = GET_PATH_WITHOUT_FILE(PATH_FULL_ALIF);
    }
  }

  // -------------------
  // Get Temp Path
  // -------------------

  PATH_TEMP = "/tmp";

  // -------------------
  // Other Path
  // -------------------

  PATH_FULL_GCC = "g++";
  PATH_FULL_CPP = PATH_TEMP + "/alifcompiler_" + RANDOM + ".cpp";
  PATH_FULL_OBJ = PATH_TEMP + "/alifcompiler_" + RANDOM + ".o";
  PATH_FULL_RC = "";
  PATH_FULL_ICO = "";

  PATH_FULL_LIB_SETTING = "/usr/local/lib/aliflib/aliflib.inf";

#endif

  // TODO(aboualiaa): check installation..
  // trim all var..
  // check gcc installation.. return false;
  // tray create file to check for errors..
  // if mac, be sure PATH_FULL_BIN end with ".app"

  if (PATH_FULL_BIN == PATH_FULL_LOG) {
    ALIF_ERROR("ERROR: The binary file and the log, is the same.");
  }

  if (working_directory.empty()) {
    ALIF_ERROR("ERROR: Can't get Working Path. \n");
    return false;
  }

  // Fix GNU LD Bug.
  if (PATH_FULL_BIN.find("Windows") != std::string::npos) {
    ALIF_ERROR("ERROR: Alif can't run from a path contain the word 'Windows', "
               "do a GNU LD Bug. \nPath: " +
               PATH_FULL_BIN +
               "\nPlease rename the folder 'Windows' to samthing else and tray "
               "again. \n");
    return false;
  }

  /*
  cout << "PATH_ABSOLUTE		: " << PATH_ABSOLUTE << endl;
  cout << "working_directory		: " << working_directory << endl <<
  endl; cout << "PATH_FULL_ALIF		: " << PATH_FULL_ALIF << endl; cout <<
  "PATH_FULL_BIN		: " << PATH_FULL_BIN << endl; cout <<
  "PATH_FULL_LOG		: " << PATH_FULL_LOG << endl << endl; cout <<
  "PATH_FULL_GCC		: " << PATH_FULL_GCC << endl; cout <<
  "PATH_FULL_CPP		: " << PATH_FULL_CPP << endl; cout <<
  "PATH_FULL_OBJ		: " << PATH_FULL_OBJ << endl; cout <<
  "PATH_FULL_RC		: " << PATH_FULL_RC << endl; cout << "PATH_FULL_ICO
  : " << PATH_FULL_ICO << endl << endl; #if  __APPLE__ cout <<
  "PATH_FULL_BIN_TMP	: " << PATH_FULL_BIN_TMP << endl; cout <<
  "PATH_FULL_PLIST		: " << PATH_FULL_PLIST << endl; #endif
  exit(EXIT_FAILURE);
  */

  return true;
}
