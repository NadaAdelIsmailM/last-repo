#ifndef BUZZER_H
#define BUZZER_H

#include "Component.h"

class Buzzer:public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Draw(UI*);
	virtual void Load(string label, int value);
	virtual void savecommponnent(fstream& file);
	virtual Buzzer* copy();
};
	virtual void Load2(int Value, string Label);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();

};
#endif