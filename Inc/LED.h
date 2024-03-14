/*
 * LED.h
 *
 *  Created on: 13 mar 2024
 *      Author: qwert
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#define BLACK 0x00000000
#define RED 0x000000FF
#define GREEN 0x0000FF00
#define BLUE 0x00FF0000

#include "tim.h"

namespace LED
{
	extern TIM_HandleTypeDef* PWM_timer;
	void SetColor(uint32_t);
	void init(TIM_HandleTypeDef*);
}


#endif /* INC_LED_H_ */
