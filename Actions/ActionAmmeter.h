#pragma once
#include "Action.h"

class ActionAmmeter : public Action
{
private:
	int x, y;
public:
	ActionAmmeter(ApplicationManager* pApp);
	~ActionAmmeter();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};



#pragma once
