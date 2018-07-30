/*
 * dice_roller.h
 *
 *  Created on: Jul 18, 2018
 *      Author: bhart
 */

#ifndef __DICE_ROLLER_H__
#define __DICE_ROLLER_H__

typedef struct tagDie {
	int sides;
	int current_val;
} Die;

void launch_dice_roller();


#endif /* __DICE_ROLLER_H__ */
