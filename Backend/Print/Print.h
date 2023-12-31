/*
 * @brief Prints the information of the accounts
 * or other information related to the criation of
 * the accounts
 *
 * @author Luís Martins (luisdfm03@gmail.com)
 * @bugs No know bugs
 */
#pragma once

/*
 * Creates the number of passwords desired and prints them in order
 * Note: The passwords created will be stored in the array passwords
 */
void get_passwords(char passwords[][MAX_LENGTH_PASSWORD], const unsigned int number_to_generate);

/**
 * Clears the terminal
 */
void clear_terminal();

/**
 * Reades the input and converts to number
 * Note: If the input is NULL it returns -1
 */
int get_input_number(char *buff, char *last_element_in_buff);
