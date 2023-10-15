#include "Test_Password.h"
#include "../../Password/Password.h"

#include <stdlib.h>

#define PASS_TESTS 1
#define FAIL_TESTS -1
#define NUMBER_OF_VALIDATIONS 4

int is_lowercase(char c)
{
    return c >= 'a' && c <= 'z'; 
}

int is_uppercase(char c)
{
    return c >= 'A' && c <= 'Z';
}

int is_number(char c)
{
    return c >= '0' && c <= '9';
}

int check_is_strong_password(char *pass)
{
    int i = 0;
    int validations[NUMBER_OF_VALIDATIONS];
    do 
    {
        if (pass[i] < 32 || pass[i] > 126)
            return 0;
        
        if (is_lowercase(pass[i]))
            validations[0] = 1;
        else if (is_uppercase(pass[i]))
            validations[1] = 1;
        else if (is_number(pass[i]))
            validations[2] = 1;
        else
            validations[3] = 1; //This validation is is_symbol
        i++;
    } while (pass[i] != '\0');

    i = 0;
    do 
    {
        if (validations[i])
            return FAIL_TESTS;
        i++;
    } while (i < NUMBER_OF_VALIDATIONS);

    return PASS_TESTS;
}

int test_password()
{
    int result = 1;
    for (int i = 0; i < 100; i++)
    {
        char *test = password_generator();
        result = check_is_strong_password(test);
        free(test);
        if (!result)
            return FAIL_TESTS;
    }

    return PASS_TESTS;
}
