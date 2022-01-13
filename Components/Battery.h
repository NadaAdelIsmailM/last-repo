#ifndef BATTERY_H
#define BATTERY_H
#include "Component.h"

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void savecommponnent(fstream& file);
	virtual void Load(string label, int value);
	virtual Battery* copy();
	virtual void Operate();
	virtual void Load2(int Value,string Label);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};
#endif