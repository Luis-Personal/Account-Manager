#define INPUT_NUMBER_INVALID 1
#define DEFAULT_PASSWORDS_TO_GENERATE 5

#include "Password_Generator/Password_Generator.h"
#include "Print_Account/Print_Account.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * Generates a random strong password and displays it
 */
int main(){
    char buff[BUFSIZ];
    char *last_element_in_buff;
    int number_of_password_generated = 0;
    
    clear_terminal();
    printf("How many password do you want to generate?\n> ");
    if(fgets(buff, sizeof(buff), stdin) != NULL)
        number_of_password_generated = strtol(buff, &last_element_in_buff, 10);
    if(!(buff[0] !=  '\n' && (*last_element_in_buff == '\n' || *last_element_in_buff == '\0')))
        return INPUT_NUMBER_INVALID;
    
    if(number_of_password_generated < 1)
        number_of_password_generated = DEFAULT_PASSWORDS_TO_GENERATE;

    char passwords[number_of_password_generated][MAX_LENGTH_PASSWORD];
    int pass_choosen = 0;
    
    do {
        printf("Which password do you want to use?\n");
        get_passwords(passwords, number_of_password_generated); 
  
        printf("Choice > ");
        if(fgets(buff, sizeof(buff), stdin) != NULL)
            pass_choosen = strtol(buff, &last_element_in_buff, 10);

        if(pass_choosen < 1 || pass_choosen > number_of_password_generated)
        {
            clear_terminal();
            printf("Please choose an option between 1 and %d\n", number_of_password_generated);
        }
    } while(pass_choosen < 1 || pass_choosen > number_of_password_generated);
    
    char *password = passwords[pass_choosen - 1];
    printf("%s\n", password);
    return EXIT_SUCCESS;
}

