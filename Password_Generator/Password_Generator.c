/*
 * @file Password_Generator.c
 * @brief Implements the Passowrd_Generator.h 
 *
 * @author Luís Martins (luisdfm03@gmail.com)
 * @bug No known bugs
*/

#include <bits/time.h>
#define MIN_CHARACTER_PRINTABLE 32
#define MAX_CHARACTER_PRINTABLE 126
#define NUMBER_OF_VALIDATIONS 4

#include "Password_Generator.h"
#include <stdlib.h>
#include <time.h>

/**
 * Gets a random value in the interval [min, max[
 */
int getRandomValue(int max, int min)
{
    return (rand() % max) + min;
}

/*
 * Checks if position has already been used
 */
int position_beeing_used(int *positions_used, const int size, const int position)
{
    int index = 0;
    while(index < size)
    {
        if(positions_used[index] == position)
            return 1;
        index++;
    }
    return 0;
}

int getRandomNumber()
{
    return getRandomValue(48, 57);
}

int getRandomUppercaseChar()
{
    return getRandomValue(65, 90);
}

int getRandomLowercaseChar()
{
    return getRandomValue(97, 122);
}

int getRandomSymbol()
{
    return getRandomValue(32, 47);
}

/**
 * Makes sure the password is considered a strong password
 * Nota: A strong password as at least one number, one symbol, one lowercase
 * letter and one uppercase letter
 */
void get_strong_password(char *password, int length)
{
    int positions_used[NUMBER_OF_VALIDATIONS];
    int index = 0,
        position = rand() % length;
    password[position] = getRandomNumber();
    positions_used[index++] = position;
    while(index < NUMBER_OF_VALIDATIONS)
    {
        position = rand() % length;
        while(position_beeing_used(positions_used, index, position))
                position = rand() % length;
        
        if (position == 2)
            password[position] = getRandomLowercaseChar();
        else if (position == 3)
            password[position] = getRandomUppercaseChar();
        else
            password[position] = getRandomSymbol();

        positions_used[index++] = position;
    }
}

char *password_generator()
{
    int max_length = MAX_LENGTH_PASSWORD - MIN_LENGTH_PASSWORD,
        max_character = MAX_CHARACTER_PRINTABLE - MIN_CHARACTER_PRINTABLE;
    
    struct timespec seed;
    if (clock_gettime(CLOCK_REALTIME, &seed) == -1)
        return "Clock Error";
    srand(seed.tv_nsec); //Make sure random doesn't give always the same
    int length = getRandomValue(max_length, MIN_LENGTH_PASSWORD); 
    char *password = (char *) malloc(length * sizeof(char));
    
    int i = 0;
    while(i  < length )
        password[i++] = getRandomValue(max_character, MIN_CHARACTER_PRINTABLE);
    get_strong_password(password,length); 
    password[length - 1] = '\0';
    
    return password;
}
