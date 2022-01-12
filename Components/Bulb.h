#pragma once
#include"Resistor.h"
#include "Component.h"
class Bulb :public virtual Component
{
	bool IsOn,IsSelected;
	Resistor internalres;
public:
	Bulb(GraphicsInfo* r__GfxInfor);
	Bulb(GraphicsInfo* r__GfxInfor,string n);
	//Bulb(GraphicsInfo* r_GfxInfo,bool IsOn);
	virtual void Operate();
	virtual void Draw(UI*);
	virtual void Load(string label, int value);
	virtual void savecommponnent(fstream& file);
	virtual Bulb* copy();
};
