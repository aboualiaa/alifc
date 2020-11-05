#!/usr/bin/env bash

#set -e

./repo_tools/clang-format-all.sh # c, c++
./repo_tools/black-all.sh        # python
./repo_tools/cmake-format-all.sh ./repo_tools/cmake-format.json
