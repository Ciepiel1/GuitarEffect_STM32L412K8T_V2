/*
 * LED.h
 *
 *  Created on: 12 mar 2024
 *      Author: qwert
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "tim.h"

namespace LED
{
	TIM_HandleTypeDef* LED_timer_ptr;
	void init(TIM_HandleTypeDef* tim)
	{
		LED_timer_ptr = tim;
		HAL_TIM_PWM_Start(LED_timer_ptr, TIM_CHANNEL_1);		//init 3 PWM channels for RGB
		HAL_TIM_PWM_Start(LED_timer_ptr, TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(LED_timer_ptr, TIM_CHANNEL_3);
	}
	void setColor(uint32_t color)
	{
		uint8_t red = color;
		uint8_t green = color>>8;
		uint8_t blue = color>>16;
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 1000-blue); //blue
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 1000-green); //green
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 1000-red); //red
	}
}


#endif /* INC_LED_H_ */
