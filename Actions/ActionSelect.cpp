#include "ActionSelect.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}
void ActionSelect::Execute() {
	UI* pUI = pManager->GetUI();//Gets a pointer to the user interface
	x = pUI->getXnew();//Gets the coordinates which the user clicked on
	y = pUI->getYnew();
	Component* comp1 = pManager->GetComponentByCoordinates(x, y);
	Connection* conn1 = pManager->GetConnByCoordinates(x, y);
	if (comp1 != nullptr){
		
		comp1->theSelection();
	}
	else if (conn1 != nullptr) {
		 
		conn1->Selection();
	}

}
void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}