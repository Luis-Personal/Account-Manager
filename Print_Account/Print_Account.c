#include "Print_Account.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_terminal()
{
    printf("\e[1;1H\e[2J");
}

void get_passwords(char passwords[][MAX_LENGTH_PASSWORD], const unsigned int number_to_generate)
{
   unsigned int index = 0;
    while (index < number_to_generate)
    {
        char *pass = password_generator();
        strcpy(passwords[index], pass);
        free(pass);
        printf("%d > %s\n", index + 1, passwords[index]);
        index++;
    }
}
