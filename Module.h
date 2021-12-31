#pragma once
#include "Components/Component.h"
class Module : public Component
{
private:

public:
	Module(GraphicsInfo* r_GfxInfo);
	Module(GraphicsInfo* r_GfxInfo, string b);
	
	
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	UI* pUI;
	virtual void Load(string label, int value);
	void  Module::savecommponnent(fstream& file);
};

