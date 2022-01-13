#pragma once
#include "Actions/ActionSelect.h"
#include "Actions/Action.h"
#include"ApplicationManager.h"
//#include "..\Components\Resistor.h"

//Class responsible for adding a new resistor action
class ActionPaste : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	//string rname;
public:
	ActionPaste(ApplicationManager* pApp);
	virtual ~ActionPaste(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
