#include "ActionSelect.h"
#include "..\ApplicationManager.h"
#include "../UI/UI.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}
void ActionSelect::Execute() {
	UI* pUI = pManager->GetUI();//Gets a pointer to the user interface
	pUI->GetLastPointClicked(x, y);
	Component* comp1 = pManager->GetComponentByCoordinates(x, y);
	Connection* conn1 = pManager->GetConnByCoordinates(x, y);
	if (comp1 != nullptr) {

		comp1->Select();
	}
	

	if (conn1 != nullptr) {
 
		conn1->Select();
	}
	else {

		pManager->UnselectAll();
	}
	//pUI->ClearDrawingArea();
	pManager->UpdateInterface();



}
void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}