#ifndef FUZE_H
#define FUZE_H
#include "Component.h"

class Fuse :public Component
{
public:
	Fuse(GraphicsInfo* r_GfxInfo);
	
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load2(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};
#endif
