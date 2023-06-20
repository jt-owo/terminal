#include "include/input.h"

input_buffer_t *new_buffer()
{
    input_buffer_t *inputBuffer = calloc(1, sizeof(input_buffer_t));
    inputBuffer->buffer = NULL;
    inputBuffer->buflen = 0;
    inputBuffer->inlen = 0;

    return inputBuffer;
}

void free_buffer(input_buffer_t *inputBuffer)
{
    free(inputBuffer->buffer);
    free(inputBuffer);
}

void read_buffer(input_buffer_t *inputBuffer)
{
    size_t bytes = getline(&(inputBuffer->buffer), &(inputBuffer->buflen), stdin);

    if (bytes <= 0)
    {
        printf("Error reading input\n");
        free_buffer(inputBuffer);
        exit(EXIT_FAILURE);
    }

    // Ignore trailing newline
    inputBuffer->inlen = bytes - 1;
    inputBuffer->buffer[bytes - 1] = 0;
}

CMDRESULT exec_command(input_buffer_t *inputBuffer)
{
    if (strcmp(inputBuffer->buffer, CMD_STR_QUIT) == 0)
    {
        free_buffer(inputBuffer);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(inputBuffer->buffer, CMD_STR_HELP) == 0)
    {
        print_help();
    }
    else
    {
        return COMMAND_UNRECOGNIZED;
    }

    return COMMAND_SUCCESS;
}

void print_info()
{
    printf("%s v%s\n\n", TERMINAL_NAME, TERMINAL_VERSION);
}

void print_prompt()
{
    printf("> ");
}

void print_help()
{
    printf("\t\t\t %s Help\n", TERMINAL_NAME);
    printf("\t\t'-q'\t\t - Quits the application.\n");
    printf("\t\t'-h'\t\t - Shows all commands.\n");
}

void print_error(char *buffer)
{
    printf("Unrecognized command '%s'\n", buffer);
    printf("Type -h to show all commands.\n");
}