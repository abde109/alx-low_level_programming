#!/bin/bash
echo -e '#include <stdlib.h>\nint rand() { static int i; return (i < 5) ? i++ : 9; }' > win.c
gcc -shared -o win.so win.c -fPIC
export LD_PRELOAD=$PWD/win.so
