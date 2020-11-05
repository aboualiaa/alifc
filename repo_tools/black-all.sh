#!/usr/bin/env bash

set -e

find . \
  -not \( -path "./cmake-build-*" -prune \) \
  \( -name '*.py' \) |
  parallel -j +2 --eta --bar --max-args=1 black -q -l 80 {}
