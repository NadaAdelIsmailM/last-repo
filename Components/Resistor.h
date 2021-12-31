#pragma once
#include "Component.h"

class Resistor:public Component
{
	
public:
	Resistor(GraphicsInfo* r_GfxInfo);
	Resistor(GraphicsInfo *r_GfxInfo,string b);
	Resistor();
	
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Load(string label, int value);
	void  Resistor::savecommponnent(fstream& file);
};
