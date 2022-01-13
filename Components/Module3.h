#pragma once
#include "Component.h"

class Module3 :public Component
{
public:
	Module3(GraphicsInfo* r_GfxInfo);
	Module3(GraphicsInfo* r_GfxInfo, string b);
	virtual void Draw(UI*);	
	virtual void Operate();
	virtual void Load2(int Value, string Label);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};