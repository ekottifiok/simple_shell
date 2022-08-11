#! /bin/bash
betty-doc *.c *.h; betty *.c *.h; betty-style *.c *.h
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c && valgrind ./a.out --track-origins=yes -s --leak-check=full --show-leak-kinds=all
