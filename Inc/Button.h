/*
 * Button.h
 *
 *  Created on: Feb 27, 2024
 *      Author: qwert
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "stdint.h"
#include "tim.h"
#include "gpio.h"
#include "Pin.h"
//defining macros (in ms) for time constants used to handle button behaviour
#define DEBOUNCE_TIME 20
#define LONG_CLICK_TIME 1000
#define DOUBLE_CLICK_TIME 500

enum ButtonClickState
{
	idle,
	first_pressed,
	first_released,
	second_pressed,
	LONG_CLICK,
	SINGLE_CLICK,
	DOUBLE_CLICK,
	handled
};

enum ButtonState
{
	Confirmed_HIGH,
	Confirmed_LOW
};

class Button
{
private:
	const Pin ButtonPin;
	GPIO_PinState PinState = GPIO_PIN_RESET;
	ButtonState DebouncedState = Confirmed_LOW;
	ButtonClickState ClickState = idle;


public:
	Button(GPIO_TypeDef*, uint16_t);

	bool isDebouncing = false;
	uint32_t Debounce_timer; 				//counting in ms
	uint32_t Click_timer;
	TIM_HandleTypeDef* Timer_ptr = &htim6; 	//timer handling debouncing and clicking routines, interrupt every 1ms

	uint16_t GetPinNum() const;

	GPIO_PinState GetPinState();
	void SetPinState(GPIO_PinState);

	ButtonState GetDebouncedState();
	void SetDebouncedState(ButtonState);

	ButtonClickState GetClickState();
	void SetClickState(ButtonClickState);

	void MainLoopClickingRoutine();

	void DebouncingRoutine();

	void ClickTimingRoutine();

	void StartDebouncing();




};


#endif /* INC_BUTTON_H_ */
