#pragma once
//#include <iostream>
//#include <fstream>

//#include "..\ApplicationManager.h"
#include "Action.h"
//#include "../Components/Component.h"


class Load: public Action{
public:

	Load(ApplicationManager* pApp);
	virtual void Undo();
	virtual void Redo();
	virtual void Execute();
	virtual ~Load(void);
};
