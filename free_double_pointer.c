//
// Created by ifiokekott on 8/5/22.
//

#include "shell.h"

void free_double_pointer(char **ptr, size_t ptr_size)
{
    size_t iteration;

    for (iteration = 0; iteration < ptr_size; iteration++)
        free(ptr[iteration]);

    free(ptr);
}