/*
 * stdafx.c
 *
 *  Created on: Jul 18, 2018
 *      Author: bhart
 */

#include "stdafx.h"

/** Common functions */

/** Saves the user's results to a file after prompting them for the path name for the file. Allows
 * the user to press ENTER to cancel the save during the prompting process.  Saves the formatted data
 * provided to the file.  Format string must be compatible with printf and a double variable type.
 */
void save_results_to_file(const char* format_string, double results) {
	char path_buff[256];	 /* 256 = MAX_PATH + 1 */

	do_prompt_file_name("\n> Path for saving results (blank to cancel) > ", path_buff, 256);

	if (path_buff[0] == '\0' || strlen(path_buff) == 0) {
		printf("\nNot saving to a file.\n");
		return;
	}

	if (format_string == NULL || format_string[0] == '\0' || strlen(format_string) == 0){
		log_error("The required parameter format_string was omitted in the save_results_to_file function.");
		return;
	}

	save_text_to_file(path_buff, format_string, results);

	printf("\nYour results have been saved to the file '%s'.", path_buff);
}
