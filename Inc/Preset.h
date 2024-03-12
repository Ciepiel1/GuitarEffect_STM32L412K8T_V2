/*
 * Preset.h
 *
 *  Created on: 8 mar 2024
 *      Author: qwert
 */

#ifndef INC_PRESET_H_
#define INC_PRESET_H_

#define NUM_OF_PARAMS 5
#define NUM_OF_PRESETS 4
#include <vector>
//#include <fstream>
#include <string>
class Preset
{
private:
	int parameters[NUM_OF_PARAMS]; //attack release threshold compression volume

public:
	void LoadPreset();
	void SavePreset();
	std::string getPresetString();
	Preset();
	Preset(const Preset& other);
	void PrintPreset();
};

struct PresetsHandle
{
private:
	std::vector<Preset*> PresetList; //to trzeba przemyslec
	Preset** CurrentPresetPtr;
	PresetsHandle();

public:

	static PresetsHandle& getInstance();
	void NextPreset();
	void LoadAllPresets();
	void SaveAllPresetsToFile();
	void PrintAllPresets();
	void SaveCurrentPreset();
	int getPresetNum(Preset*);
	Preset* getCurrentPreset();
	~PresetsHandle();
};

#endif /* INC_PRESET_H_ */
