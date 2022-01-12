#include "ActionSelectComponent.h"
#include "..\ApplicationManager.h"
#include "../Components/Connection.h"

ActionSelectComponent::ActionSelectComponent(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionSelectComponent::Execute()
{
	Component* cmp1 = nullptr;
	UI* pUI = pManager->GetUI();

	pUI->PrintMsg("selecting a component");

	pUI->GetPointClicked(x1, y1);
	cmp1 = pManager->ValidPoint(x1, y1);
	while (cmp1 == nullptr)
	{
		pUI->PrintMsg("Error!!! Invalid Selection point. Click agian to select component.");
		pUI->GetPointClicked(x1, y1);
		cmp1 = pManager->ValidPoint(x1, y1);
	};
	cmp1->setselect(!(cmp1->IsSelected()));

	pUI->ClearStatusBar();

	cmp1->Draw(pUI);
}

void ActionSelectComponent::Undo()
{}

void ActionSelectComponent::Redo()
{}

