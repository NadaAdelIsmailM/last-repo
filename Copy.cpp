/*#include "Copy.h"
#include "ActionCopy.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "ActionSelect.h"
#include "ActionSelect.cpp"

ActionCopy::ActionCopy(ApplicationManager* pApp) :Action(pApp)
{
}

ActionCopy::~ActionCopy(void)
{
}

void ActionCopy::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
//	pUI->PrintMsg("Add the label you want ");
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

	Component* pointer = pManager->getx();
	pManager->setcopycomponent(pointer);
	//Resistor* pR = new Resistor(pGInfo, rname);
	//pManager->AddComponent(pR);

}

void ActionCopy::Undo()
{}

void ActionCopy::Redo()
{}*/
