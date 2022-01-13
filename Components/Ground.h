#ifndef GROUND_H
#define GROUND_H
#include "Component.h"

class Ground :public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load2(int Value, string Label);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};

#endif
