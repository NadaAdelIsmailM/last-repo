#pragma once
#include "Component.h"
#include "Switch.h"
class fuse :public Component
{
private:
	int  max_current;
public:
	fuse(GraphicsInfo* r_GfxInfo);
	fuse(GraphicsInfo* r_GfxInfo,string k,string max_current);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Load(string label, int value);
	virtual void  fuse::savecommponnent(fstream& file);
	virtual bool belw(int current);
};