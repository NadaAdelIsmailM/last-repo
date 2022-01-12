#pragma once
#include"Resistor.h"

class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	virtual void Operate();
	virtual void Draw(UI*);
};