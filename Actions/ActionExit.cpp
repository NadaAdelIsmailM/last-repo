#include "ActionExit.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"

ActionExit::ActionExit(ApplicationManager* pApp):Action(pApp)
{
}

ActionExit::~ActionExit(void)
{
}
void ActionExit::Execute()
{
//	pManager->DelAll();
}
void ActionExit::Undo()
{}

void ActionExit::Redo()
{}