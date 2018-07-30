/*
 * c103.c
 *
 *  Created on: Jul 18, 2018
 *      Author: bhart
 */

#include "stdafx.h"

#include "c103.h"
#include "dice_roller.h"
#include "circle_area_finder.h"
#include "cube_volume_finder.h"

void print_goodbye(void);

int main(void) {
	clear_screen();

	int choice = 0;

	// Seed the random number generator so we get a unique sequence of random
	// numbers per each program invocation (for the dice roller game)
	srand(time(0));

	while ((choice = print_menu()) != IDM_APP_EXIT) {
		/* Keep showing the menu items */
		switch(choice) {
			case IDM_GAMES_DICE_ROLLER:
				launch_dice_roller();
				break;

			case IDM_GEOMETRY_FIND_CIRCLE_AREA:
				launch_circle_area_finder();
				break;

			case IDM_GEOMETRY_FIND_CUBE_VOLUME:
				launch_cube_volume_finder();
				break;

			case IDM_SPECIAL_REVERSER:
				clear_screen();
				launch_special_reverser();
				break;
		}
	}

	print_goodbye();

	return 0;
}

int print_menu() {
	clear_screen();

	char* menu[15] = {
			"==================================================================",
			"==                             MATH FUN                         ==",
			"==================================================================",
			"",
			"            MAIN MENU - PLEASE CHOOSE YOUR SELECTION",
			"            ========================================",
			"",
			"    [1] DICE ROLLER GAME",
			"    [2] CALCULATE AREA OF A CIRCLE",
			"    [3] CALCULATE VOLUME OF A CUBE",
			"    [4] SPECIAL FUNCTION: REVERSE A STRING",
			"    [5] QUIT",
			"",
			"==================================================================",
			"",
	};

	print_strings(menu, 15);

	char buff[2];

	int retcode = get_line_with_default("> Enter your choice (1-5) > ", buff, "5", 2);

	log_debug("buff = '%s'", buff);

	if (retcode != OK && retcode != EXACTLY_CORRECT){
		printf("Input was not in a valid format.\n");
		return IDM_APP_EXIT;
	}

	if (!isdigit(buff[0])) {
		printf("Input was not in a valid format. The input must be a numeric digit.\n");
		return IDM_APP_EXIT;
	}

	long choice = 0;

	char_to_long(buff, &choice);

	return (int)((-1 * 600) - choice);
}

void print_goodbye() {
	clear_screen();

	char* goodbye[15] = {
				"==================================================================",
				"==                             MATH FUN                         ==",
				"==================================================================",
				"",
				"",
				"",
				"",
				"              THANKS FOR USING THE MATH FUN APPLICATION!",
				"                          HAVE A NICE DAY!",
				"",
				"",
				"",
				"",
				"==================================================================",
				"",
		};

	print_strings(goodbye, 15);

	printf("\n");
}
