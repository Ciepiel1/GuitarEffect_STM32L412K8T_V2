/*
 * Menu.h
 *
 *  Created on: 8 mar 2024
 *      Author: qwert
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_

#include "State.h"
class State; //Dlaczego musze to zadeklarowac zeby dzialalo????

class Menu
{
private:
	State* CurrentState;
	//PresetsHandle* presets_ptr;
public:
	Menu();
	State* getState() const { return CurrentState; };
	void setState(State& newState);
	void SingleClick();
	void LongClick();
	void DoubleClick();
};

#endif /* INC_MENU_H_ */
