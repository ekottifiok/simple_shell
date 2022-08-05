#! /bin/bash
betty-doc *.c; betty *.c; betty-style *.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c && valgrind ./a.out --track-origins=yes -s --leak-check=full --show-leak-kinds=all
