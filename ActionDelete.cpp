#include "ActionDelete.h"
#include "Connections/Connection.h"
#

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionDelete::Execute()
{
	pManager->DeleteComp();
	pManager->DeleteConn();
}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}

