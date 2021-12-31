#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo);
	Switch(GraphicsInfo* r_GfxInfo,string b);
	virtual void Operate();	//open or close the circuit
	virtual void Draw(UI*);	//Draws the switch
	virtual void Load(string label, int value);
	virtual void  Switch::savecommponnent(fstream& file);
};
 
