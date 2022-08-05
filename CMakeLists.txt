cmake_minimum_required(VERSION 3.23)
project(simple_shell C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(simple_shell
        prompt.c
        shell.c
        parser.c
        _realloc.c
        execute_command.c
        execute_decision.c
        free_double_pointer.c
        shell.h get_env_variable.c complete_path.c get_builtin_function.c change_directory.c)
