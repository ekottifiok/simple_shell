#! /bin/bash
betty-doc *.c; betty *.c; betty-style *.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c && valgrind ./a.out --track-origins=yes
