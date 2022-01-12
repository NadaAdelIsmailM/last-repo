#include "ActionPaste.h"
#include "Components/Component.h"
#include "Actions/ActionSelect.h"


ActionPaste::ActionPaste(ApplicationManager* pApp) :Action(pApp)
{
}

ActionPaste::~ActionPaste(void)
{
}

void ActionPaste::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("click where you want to add ");
	//	rname = pUI->GetString();

		//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	pUI->PrintMsg("enter the label ");
	string label = pUI->GetString();
	pUI->ClearStatusBar();
	//Component* c = pManager->paste();
	//pManager->AddComponent(c);

	//Resistor* pR = new Resistor(pGInfo, rname);
	//pManager->AddComponent(pR);

}

void ActionPaste::Undo()
{}

void ActionPaste::Redo()
{}

