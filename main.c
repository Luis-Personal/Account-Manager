#include "Password_Generator/Password_Generator.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Generates a random strong password and displays it
 */
int main(){
    char *password = password_generator();
    
    printf("%s\n", password);
    free(password);
    return 0;
}
