/*
 * @file Password_Generator.h
 * @brief Creates a random word/password, that is considered strong
 *
 * @author Luis Martins (luisdfm03@gmail.com)
 * @bug No known bugs.
 */

#pragma once
#define MIN_LENGTH_PASSWORD 14
#define MAX_LENGTH_PASSWORD 36

/*
 * Generates a random strong password
 */
char *password_generator();
