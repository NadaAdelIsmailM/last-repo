#pragma once
#include "Component.h"

class elabel :public Component
{
public:
	elabel(GraphicsInfo* r_GfxInfo);
	virtual void set_label(string a);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void savecommponnent(fstream& file);
	virtual void Draw(UI*);
	virtual void Load(string label, int value);
	virtual void copy();
};