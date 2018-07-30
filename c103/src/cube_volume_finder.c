/*
 * cube_volume_finder.c

 *
 *  Created on: Jul 19, 2018
 *      Author: bhart
 */

#include "stdafx.h"
#include "cube_volume_finder.h"

long get_side_length(void);


char* cube_volume_titlebar[4] = {
	"==================================================================",
	"==                      CUBE VOLUME FINDER                      ==",
	"==================================================================",
	""
};

void launch_cube_volume_finder() {
	clear_screen();

	print_strings(cube_volume_titlebar, 4);

	long side_length = get_side_length();

	double volume = volume_of_cube((double)side_length);

	printf("\nThe volume of the cube is approx. %0.2f cubic meters!\n", volume);

	/* Allow the user the option to save to a file */
	save_results_to_file("The volume of the cube is approx. %0.2f cubic meters!", volume);

	prompt_for_key_press();
}

long get_side_length(void) {
	long result = 0;

	char side_length_buffer[3];

	int retcode = get_line("> Enter side length of cube (max. 99 meters)? > ", side_length_buffer, 3);

	if ((retcode != OK && retcode != EXACTLY_CORRECT) || !is_numbers_only(side_length_buffer)) {
		printf("ERROR: Please input a numeric value not greater than 99 meters.\n");
		printf("ERROR: Only whole numbers are allowed.\n");
		exit(-1);
	}

	retcode = char_to_long(side_length_buffer, &result);

	if (retcode != OK && retcode != EXACTLY_CORRECT){
		printf("ERROR: Unable to read the side length from the input typed.\n");
		exit(-1);
	}

	if (result >= 100){
		printf("ERROR: Please input a value no greater than 99 meters.\n");
		exit(-1);
	}

	if (result <= 0){
		printf("ERROR: Please input a side length that is greater than zero meters.\n");
		exit(-1);
	}

	return result;
}
