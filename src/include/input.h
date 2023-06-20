#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define true 1
#define false 0

#define TERMINAL_NAME "Terminal"
#define TERMINAL_VERSION "0.1"

#define CMD_STR_HELP "-h"
#define CMD_STR_QUIT "-q"

typedef enum
{
    COMMAND_SUCCESS,
    COMMAND_UNRECOGNIZED,
} CMDRESULT;

typedef struct
{
    char *buffer;
    size_t buflen;
    size_t inlen;
} input_buffer_t;

input_buffer_t *new_buffer();
void free_buffer(input_buffer_t *inputBuffer);
void read_buffer(input_buffer_t *inputBuffer);

CMDRESULT exec_command(input_buffer_t *inputBuffer);

void print_info();
void print_prompt();
void print_help();
void print_error(char *buffer);

#endif