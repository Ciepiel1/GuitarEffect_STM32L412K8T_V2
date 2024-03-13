/*
 * LED.cpp
 *
 *  Created on: 13 mar 2024
 *      Author: qwert
 */


#include "LED.h"

void LED::SetColor(uint32_t color)
{
	uint8_t red = color;
	uint8_t green = color>>8;
	uint8_t blue = color>>16;

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 1000-blue);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 1000-green); //green
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 1000-red); //red
}
