#! /bin/bash
betty-doc *.c *.h; betty *.c *.h; betty-style *.c *.h
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
echo "env" | ./a.out
