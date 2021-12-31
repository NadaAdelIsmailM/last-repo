#include "ActionEditLabel.h"
#include "..\ApplicationManager.h"



ActionEditLabel::ActionEditLabel(ApplicationManager* pApp) :Action(pApp)
{
}

ActionEditLabel::~ActionEditLabel(void)
{
}

void ActionEditLabel::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("which component do you want to edit its label ?");
	sname = pUI->GetString();

	//Get Center point of the area where the Comp should be drawn


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

	elabel*pR = new elabel(pGInfo);
	pManager->AddComponent(pR);
}

void ActionEditLabel::Undo()
{}

void ActionEditLabel::Redo()
{}

