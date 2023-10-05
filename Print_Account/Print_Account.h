/*
 * @brief Prints the information of the accounts
 * or other information related to the criation of
 * the accounts
 *
 * @author Luís Martins (luisdfm03@gmail.com)
 * @bugs No know bugs
 */
#pragma once

#include "../Password_Generator/Password_Generator.h"

/*
 * Creates the number of passwords desired and prints them in order
 * Note: The passwords created will be stored in the array passwords
 */
void get_passwords(char passwords[][MAX_LENGTH_PASSWORD], const unsigned int number_to_generate);

/**
 * Clears the terminal
 */
void clear_terminal();
