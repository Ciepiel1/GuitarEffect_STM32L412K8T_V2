/*
 * Pin.h
 *
 *  Created on: 7 mar 2024
 *      Author: qwert
 */

#ifndef INC_PIN_H_
#define INC_PIN_H_

#include "gpio.h"

class Pin
{
private:
	GPIO_TypeDef* Port;
	uint16_t PinNum;
public:
	Pin(GPIO_TypeDef*, uint16_t);
	void Write(bool) const;
	void Toggle() const;
	GPIO_PinState Read() const;
	uint16_t GetNum() const;
};


#endif /* INC_PIN_H_ */
