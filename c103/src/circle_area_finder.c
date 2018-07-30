/*
 * circle_area_finder.c

 *
 *  Created on: Jul 19, 2018
 *      Author: bhart
 */

#include "stdafx.h"
#include "circle_area_finder.h"

long get_radius(void);

char* circle_area_titlebar[4] = {
	"==================================================================",
	"==                      CIRCLE AREA FINDER                      ==",
	"==================================================================",
	""
};

void launch_circle_area_finder() {
	clear_screen();

	print_strings(circle_area_titlebar, 4);

	long radius = get_radius();

	double area = area_of_circle((double)radius);

	printf("\nThe area of the circle is approx. %0.2f square inches!\n", area);

	/* Allow the user the option to save to a file */
	save_results_to_file("The area of the circle is approx. %0.2f square inches!", area);

	prompt_for_key_press();
}

long get_radius(void) {
	long result = 0;

	char radius_buffer[3];

	int retcode = get_line("> Enter radius of circle (max. 99 inches)? >", radius_buffer, 3);

	if ((retcode != OK && retcode != EXACTLY_CORRECT) || !is_numbers_only(radius_buffer)) {
		printf("ERROR: Please input a number not greater than 999 inches.\n");
		printf("ERROR: Only whole numbers are allowed.\n");
		exit(-1);
	}

	retcode = char_to_long(radius_buffer, &result);

	if (retcode != OK && retcode != EXACTLY_CORRECT){
		printf("ERROR: Unable to read the radius from the input typed.\n");
		exit(-1);
	}

	if (result >= 100){
		printf("ERROR: Please input a value no greater than 99 inches.\n");
		exit(-1);
	}

	if (result <= 0){
		printf("ERROR: Please input a radius that is greater than zero inches.\n");
		exit(-1);
	}

	return result;
}

