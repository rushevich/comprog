#!/usr/bin/env bash

set -e

if [ $# -lt 1 ]; then
    echo "Usage: $0 <source_file.cpp/c>"
    exit 1
fi

SOURCE_FILE="$1";
INPUT="$2";

g++ -std=c++17 -o test "$SOURCE_FILE" && ./test <<< "$INPUT" && rm test
