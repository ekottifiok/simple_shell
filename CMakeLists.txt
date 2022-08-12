cmake_minimum_required(VERSION 3.23)
project(simple_shell C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(simple_shell
        prompt.c
        shell.c
        _strlen.c
        _strcpy.c
        copy_string_index.c
        parse_string.c
        _realloc.c
        execute_command.c
        execute_decision.c
        free_double_pointer.c
        shell.h
        get_env_variable.c
        complete_path.c
        get_builtin_function.c
        change_directory.c
        set_env_variable.c
        exit_command.c
        echo.c
        print_working_directory.c
        help.c
        print_double_pointer.c
        _pow_recursion.c
        copy_double_pointer.c
        print_env.c
        add_node_list.c
        free_list.c
        find_control.c
        parse_multiline.c
        add_input_string.c
        free_user_input_type.c
        __getline.c
        sub_main.c
        add_input_history.c)
