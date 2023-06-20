#include "include/input.h"

typedef enum
{
    STATE_REPL
} STATE;


int main()
{
    input_buffer_t *inputBuffer = new_buffer();
    STATE state = STATE_REPL;

    print_info();

    while (true)
    {
        if (state == STATE_REPL)
        {
            print_prompt();
            read_buffer(inputBuffer);

            // A minus represents the start of a command.
            if (inputBuffer->buffer[0] == '-')
            {
                switch (exec_command(inputBuffer))
                {
                case (COMMAND_SUCCESS):
                    continue;
                case (COMMAND_UNRECOGNIZED):
                    print_error(inputBuffer->buffer);
                    continue;
                }
            }
            else
            {
                print_error(inputBuffer->buffer);
            }
        }
    }

    free_buffer(inputBuffer);

    return EXIT_SUCCESS;
}