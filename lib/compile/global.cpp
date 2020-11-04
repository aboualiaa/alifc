// ==================================
// (C)2019 DRAGA Hassan.
// (C)2019 Alif Community.
// 	 www.aliflang.org
// ----------------------------------
// Licence : GPLv3.
// ----------------------------------
// Alif Programming Language
// ==================================

#include "general/global.h"

void CompileAddExtra_Compile(std::string cmd) {
  Compile_ExtraCompile.append(cmd);
}

void CompileAddExtra_Link(std::string cmd) { Compile_ExtraLink.append(cmd); }

void PythonSetEnvirenment() {

  // -------------------------------
  // Python cmd: python3 -c "import sys; print(sys.path)"
  // Python includes	-> /usr/include/python3.5
  // Python Libs		->
  // /usr/lib/python3.5/config-3.5m-x86_64-linux-gnu python lib name	->
  // python3.5
  // -------------------------------

  // TODO: if thos var are empty, then get python paths by cmd.

  std::string buffer = " -I\"" + PythonInclude_path + "\" ";
  CompileAddExtra_Compile(buffer);
  buffer = " -L\"" + PythonLib_path + "\" -l" + PythonLibName + " ";
  CompileAddExtra_Link(buffer);
}
