#pragma once
#include"Resistor.h"

class Buzzer :public Component
{
	Resistor internalres;
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	Buzzer(GraphicsInfo* r_GfxInfo,string s);
	virtual void Operate();
	virtual void Draw(UI*);
	virtual void Load(string label, int value);
	virtual void savecommponnent(fstream& file);
	//virtual void ToSim();
};