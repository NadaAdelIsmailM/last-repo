#ifndef BULB_H
#define BULB_H

#include "Component.h"

class Bulb :public Component {
public:
	Bulb(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the Bulb
	virtual void Operate();
	virtual void Load2(int Value, string Label);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS Bulb::whichComponent();

};
#endif