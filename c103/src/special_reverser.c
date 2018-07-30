/*
 * special_reverser.c

 *
 *  Created on: Jul 19, 2018
 *      Author: bhart
 */

#include "stdafx.h"
#include "special_reverser.h"

char* get_string_to_reverse(void);
char *reverse(char *str);

char* string_reverser_titlebar[4] =
{
	"==================================================================",
	"==                   SPECIAL STRING REVERSER                    ==",
	"==================================================================",
	""
};

void launch_special_reverser() {
	clear_screen();

	print_strings(string_reverser_titlebar, 4);

	char* string_to_reverse = get_string_to_reverse();

	printf("You typed the phrase '%s'.\n", string_to_reverse);

	prompt_for_key_press();

	printf("Reversed string: '%s'\n", reverse(string_to_reverse));

	prompt_for_key_press();

	// Release the system resources associated with string_to_reverse
	free(string_to_reverse);
}

char* get_string_to_reverse(void) {
	char* result_buffer = malloc(MAX_INPUT + 1);

	int retcode = get_line("> Phrase to reverse (max. 255 chars): > ",
			result_buffer, MAX_INPUT + 1);

	if (retcode != OK && retcode != EXACTLY_CORRECT) {
		printf("ERROR: The phrase you want to reverse can be a maximum of 255 characters.");

		// Make sure to release the memory allocated with malloc before exiting, so that
		// we do not leak memory
		free(result_buffer);

		exit(-1);
	}

	return result_buffer;
}

char *reverse(char *str) {
	if (str == NULL)
		return NULL;

	char *p1, *p2;

	if (!str || !*str)
		return str;

	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}

	return str;
}
