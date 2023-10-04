/*
 * @file Password_Generator.c
 * @brief Implements the Passowrd_Generator.h 
 *
 * @author Luís Martins (luisdfm03@gmail.com)
 * @bug No known bugs
*/

#define MIN_CHARACTER_PRINTABLE 32
#define MAX_CHARACTER_PRINTABLE 126

#include "Password_Generator.h"
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

int getRandomValue(int max, int min)
{
    return (rand() % max) + min;
}

char *password_generator()
{
    int max_length = MAX_LENGTH_PASSWORD - MIN_LENGTH_PASSWORD,
        max_character = MAX_CHARACTER_PRINTABLE - MIN_CHARACTER_PRINTABLE;

    srand(time(NULL)); //Make sure random doesn't give always the same
    int length = getRandomValue(max_length, MIN_LENGTH_PASSWORD); 
    char *password = (char *) malloc(length * sizeof(char));
    
    int i = 0;
    while(i  < length)
        password[i++] = getRandomValue(max_character, MIN_CHARACTER_PRINTABLE);
    password[i] = '\0';
    
    printf("%s\n", password);
    return password;
}

int main(){
    //int i = 0;
    //while(i++ < 1)
    //    password_generator();
    char *pass = password_generator();
    free(pass);
    return 0;
}
