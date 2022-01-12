#pragma once
#include "Actions/Action.h"
#include "Components/Component.h"
#include "ApplicationManager.h"

//Class responsible for adding a new resistor action
class ActionDelete : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1;	//Two corners of the rectangluar area
public:

	ActionDelete(ApplicationManager* pApp);
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

