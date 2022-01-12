#include "ActionVoltmeter.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"


ActionVoltmeter::ActionVoltmeter(ApplicationManager* pApp) :Action(pApp)
{

}

ActionVoltmeter::~ActionVoltmeter()
{

}

void ActionVoltmeter::Execute()
{
	UI* pUI = pManager->GetUI();
	pManager->GetUI()->PrintMsg("Select the component: ");
	pUI->GetPointClicked(x, y);
	Component* pComp = pManager->GetComponentByCoordinates(x, y);
	if (pComp != nullptr)
	{
		pManager->GetUI()->GetString("The volt is= ");
	}

}

void ActionVoltmeter::Undo()
{}

void ActionVoltmeter::Redo()
{}