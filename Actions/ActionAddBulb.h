#pragma once
#include "action.h"
#include "..\Components\Bulb.h"
class ActionAddBulb : public Action
{
private:
	int Cx, Cy;
	int x1, y1, x2, y2;
	Status Compstate;
public:
	//Status Compstate;
	string Compstates;
	ActionAddBulb(ApplicationManager* pApp);
	virtual ~ActionAddBulb(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual void ToSim();
};

#pragma once
