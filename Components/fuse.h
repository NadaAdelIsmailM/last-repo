#pragma once
#include "Component.h"

class fuse :public Component
{
public:
	fuse(GraphicsInfo* r_GfxInfo);
	fuse(GraphicsInfo* r_GfxInfo,string k);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Load(string label, int value);
	virtual void  fuse::savecommponnent(fstream& file);
	virtual fuse* copy();
};