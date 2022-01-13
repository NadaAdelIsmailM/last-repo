#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor:public Component
{
public:
	Resistor(GraphicsInfo *r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Load(string label, int value);
	void  Resistor::savecommponnent(fstream& file);
};
#endif