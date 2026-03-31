#!/bin/bash

set echo on

mkdir -p Bin

cFilenames=$(find . -type f -name "*.c")

assembly="x11Window"

compilerFlags="-g"

includeFlags="-Isrc -Iinclude"

linkerFlags="-LBin -Wl,-rpath,."

echo "Building $assembly..."

echo clang $cFilenames $compilerFlags -o Bin/$assembly $defines $includeFlags $linkerFlags

clang $cFilenames $compilerFlags -o Bin/$assembly $defines $includeFlags $linkerFlags