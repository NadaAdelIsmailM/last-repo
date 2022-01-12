#include "ActionDeleteComponent.h"
#include "..\ApplicationManager.h"
#include "../Components/Connection.h"

ActionDeleteComponent::ActionDeleteComponent(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionDeleteComponent::Execute()
{
	pManager->DeleteComp();
	pManager->DeleteConn();
}

void ActionDeleteComponent::Undo()
{}

void ActionDeleteComponent::Redo()
{}

