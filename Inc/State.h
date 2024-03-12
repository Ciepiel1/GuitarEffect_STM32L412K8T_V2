/*
 * State.h
 *
 *  Created on: 8 mar 2024
 *      Author: qwert
 */

#ifndef INC_STATE_H_
#define INC_STATE_H_

#include "Menu.h"
#include "Preset.h"
//#include<iostream>
class Menu;


class State
{
private:

public:
	virtual void SingleClick(Menu* CurrentState) = 0;
	virtual void DoubleClick(Menu* CurrentState) = 0;
	virtual void LongClick(Menu* CurrentState) = 0;
	virtual void PrintState() = 0;
	virtual void SetLED() = 0;
	virtual ~State(){}
};

class IdleOn : public State
{
private:
	IdleOn(){}
	IdleOn(const IdleOn& other);
	IdleOn& operator =(const IdleOn& other);

public:
	void SingleClick(Menu* CurrentState);
	void DoubleClick(Menu* CurrentState) {};
	void LongClick(Menu* CurrentState);
	void PrintState();
	void SetLED();
	static State& getInstance();
};

class IdleOff : public State
{
private:
	IdleOff() {}
	IdleOff(const IdleOff& other);
	IdleOff& operator =(const IdleOff& other);

public:
	void SingleClick(Menu* CurrentState);
	void DoubleClick(Menu* CurrentState) {};
	void LongClick(Menu* CurrentState);
	void PrintState();
	void SetLED();
	static State& getInstance();
};

class PresetMode : public State
{
private:
	PresetsHandle* presets_ptr;

	PresetMode();
	~PresetMode();
	PresetMode(const PresetMode& other);
	PresetMode& operator =(const PresetMode& other);

public:
	void SingleClick(Menu* CurrentState);
	void DoubleClick(Menu* CurrentState);
	void LongClick(Menu* CurrentState);
	void PrintState();
	void SetLED();
	void setPresetsPtr(PresetsHandle*);
	static State& getInstance();
};

class EditPreset : public State
{
private:
	PresetsHandle* presets_ptr;

	EditPreset();
	~EditPreset();
	EditPreset(const EditPreset& other);
	EditPreset& operator =(const EditPreset& other);

public:
	void SingleClick(Menu* CurrentState);
	void DoubleClick(Menu* CurrentState);
	void LongClick(Menu* CurrentState);
	void PrintState();
	void SetLED();
	void setPresetsPtr(PresetsHandle*);
	static State& getInstance();
};

#endif /* INC_STATE_H_ */
