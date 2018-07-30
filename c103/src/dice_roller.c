/*
 * dice_roller.c
 *
 *  Created on: Jul 18, 2018
 *      Author: bhart
 */

#include "stdafx.h"
#include "dice_roller.h"

char* dice_roller_titlebar[4] = {
	"==================================================================",
	"==                        DICE ROLLER GAME                      ==",
	"==================================================================",
	""
};

Die* get_dice(int* dice_count);
int get_number_of_dice();
int get_number_of_sides(int dice_index);
int get_number_of_rolls();
int roll_die(int sides);

void launch_dice_roller(void) {
	clear_screen();

	int dice_count = 0;

	/* Get the user to create some dice.  We get back a pointer to an array of Die structures. */
	Die* dice = get_dice(&dice_count);

	if (dice_count <= 0 || dice == NULL){
		printf("ERROR: You are supposed to create more than zero dice.\n");
		free(dice);
		exit(-1);
	}

	clear_screen();

	print_strings(dice_roller_titlebar, 4);

	int roll_count = get_number_of_rolls();

	printf("\nYou have specified that you want to roll the %d dice %d times.\n", dice_count, roll_count);

	printf("Now, let's play!\n");

	prompt_for_key_press();

	clear_screen();

	print_strings(dice_roller_titlebar, 4);

	for(int i = 0;i < roll_count;i++){
		printf("\nROLL #%d of %d\n", i+1, roll_count);
		printf("============\n");

		for(int j = 0;j < dice_count;j++) {
			dice[j].current_val = roll_die(dice[j].sides);

			printf("\nDie #%d is a %d-sided die and its current value is %d.\n",
				j+1, dice[j].sides, dice[j].current_val);
		}

		printf("\n");

		prompt_for_key_press();

		clear_screen();

		print_strings(dice_roller_titlebar, 4);
	}

	free(dice);
	dice = NULL;
}

Die* get_dice(int* dice_count){
	clear_screen();

	if (dice_count == NULL){
		return NULL;
	}

	print_strings(dice_roller_titlebar, 4);

	int num_dice = get_number_of_dice();

	if (num_dice <= 0){
		printf("ERROR: Negative or zero dice count.\n");
		exit(-1);
	}

	Die* dice = (Die*)malloc(num_dice * sizeof(Die));

	printf("\n%d dice have been created!\n", num_dice);

	for(int i = 0;i < num_dice;i++) {
		dice[i].sides = get_number_of_sides(i);

		printf("\nDie #%d has been given %d sides.\n", i + 1, dice[i].sides);
	}

	*dice_count = num_dice;

	prompt_for_key_press();

	return dice;
}

int get_number_of_dice(){
	char output_buff[2];

	get_line_with_default("> How many dice do you want (1-5) ? >", output_buff, "3", 2);

	long result = 0;

	int retcode = char_to_long(output_buff, &result);

	if ((retcode != OK && retcode != EXACTLY_CORRECT) || (result < 1 || result > 5)) {
		printf("ERROR: Please enter a number between 1-5 (inclusive).\n");
		exit(-1);
	}

	return (int)result;
}

int get_number_of_sides(int dice_index){
	char output_buff[4];

	char prompt_buff[49];

	sprintf(prompt_buff, "\n> How many sides should die #%d have? (6-100) >", dice_index + 1);

	get_line_with_default(prompt_buff, output_buff, "6", 4);

	long result = 0;

	int retcode = char_to_long(output_buff, &result);

	if ((retcode != OK && retcode != EXACTLY_CORRECT) || (result < 6 || result > 100)) {
		printf("ERROR: Please enter a number between 6-100 (inclusive).\n");
		exit(-1);
	}

	return (int)result;
}

int get_number_of_rolls()
{
	char output_buff[2];

	get_line_with_default("> How many times should we roll all the dice? (1-5) >", output_buff, "3", 2);

	long result = 0;

	int retcode = char_to_long(output_buff, &result);

	if ((retcode != OK && retcode != EXACTLY_CORRECT) || (result < 1 || result > 5)) {
		printf("ERROR: Please enter a number between 1-5 (inclusive).\n");
		exit(-1);
	}

	return (int)result;
}

int roll_die(int sides) {
	if (sides <= 1) {
		return 1;
	}

	/* upper and lower ends of the range of random numbers to generate
	 * (for the values on the sides of the die and which value is pointing
	 * up when it's rolled.*/
	int upper = sides - 1;
	int lower = 1;

	// "Throw" the die
	return rand() % (upper - lower + 1) + lower;
}
