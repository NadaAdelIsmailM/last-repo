#pragma once

#include "action.h"
#include "..\Components\Connection.h"

class ActionAddConnec : public Action
{
private:
	int x1, y1, x2, y2;
public:
	ActionAddConnec(ApplicationManager* pApp);
	virtual ~ActionAddConnec(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

#pragma once
