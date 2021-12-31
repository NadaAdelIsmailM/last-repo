#pragma once

#include "Action.h"


class ActionSwitchSim : public Action
{
public:
	ActionSwitchSim(ApplicationManager* pApp);
	virtual ~ActionSwitchSim(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
