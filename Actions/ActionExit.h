#pragma once

#include "Action.h"
class ActionExit : public Action
{
public:
	ActionExit(ApplicationManager* pApp);
	virtual ~ActionExit(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
