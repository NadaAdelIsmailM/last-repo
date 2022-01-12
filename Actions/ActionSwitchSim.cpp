#include "ActionSwitchSim.h"
#include "..\ApplicationManager.h"


ActionSwitchSim::ActionSwitchSim(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSwitchSim::~ActionSwitchSim(void)
{
}

void ActionSwitchSim::Execute()
{

	if (pManager->ValidateCircuit())
	{
		UI* pUI = pManager->GetUI();
		//pUI->ClearToolBarArea();
		pUI->CreateSimulationToolBar();

		pManager->ToSim();
		//pUI->CreateSimulationToolBar();
		//pUI->CreateSimulationMode(bool sele);
	}
}
void ActionSwitchSim::Undo()
{}

void ActionSwitchSim::Redo()
{}