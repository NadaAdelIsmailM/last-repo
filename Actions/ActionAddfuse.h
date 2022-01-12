#pragma once
#pragma once

#include "Action.h"
#include "../Components/Fuse.h"
#include "../ApplicationManager.h"

//Class responsible for adding a new resistor action
class ActionAddfuse : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddfuse(ApplicationManager* pApp);
	virtual ~ActionAddfuse(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void loadcircuit();
	virtual void Undo();
	virtual void Redo();


};
