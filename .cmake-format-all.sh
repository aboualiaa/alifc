#!/usr/bin/env bash

set -e

find . \
  -not \( -path "./cmake-build-*" -prune \) \
  \( -name 'CMakeLists.txt' -o -name '*.cmake' \) |
  parallel -j 12 --eta --bar --max-args=1 cmake-format -c .cmake-format.json -i {}
