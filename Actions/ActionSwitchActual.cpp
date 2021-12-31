#include "ActionSwitchActual.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSwitchActual::ActionSwitchActual(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSwitchActual::~ActionSwitchActual(void)
{
}
void ActionSwitchActual::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->SwitchImageType();


}
void ActionSwitchActual::Undo()
{}

void ActionSwitchActual::Redo()
{}