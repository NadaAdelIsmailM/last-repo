#include "ActionAddfuse.h"
#include "../ApplicationManager.h"

ActionAddfuse::ActionAddfuse(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddfuse::~ActionAddfuse(void)
{
}

void ActionAddfuse::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Add a label to the fuse");
	fname = pUI->GetString();
	//Get Center point of the area where the Comp should be drawnf
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

	fuse* pR = new fuse(pGInfo, fname);
	pManager->AddComponent(pR);
}

void ActionAddfuse::Undo()
{}

void ActionAddfuse::Redo()
{}
