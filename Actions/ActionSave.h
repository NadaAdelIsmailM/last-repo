#pragma once

#include "action.h"
#include <iostream>
#include <fstream>
using namespace std;


//Class responsible for adding a new resistor action
class Actionsave : public Action
{
private:
	fstream file;

public:
	Actionsave(ApplicationManager* pApp);

	virtual ~Actionsave(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();

	virtual void Redo();


};
