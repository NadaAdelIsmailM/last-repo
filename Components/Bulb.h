#pragma once
#include"Resistor.h"

class Bulb :public Resistor
{
	bool IsOn;
public:
	Bulb(GraphicsInfo* r_GfxInfo,bool IsOn);
	virtual void Operate();
	virtual void Draw(UI*);

};
