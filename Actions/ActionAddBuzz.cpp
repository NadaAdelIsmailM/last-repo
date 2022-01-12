#include "ActionAddBuzz.h"
#include "..\ApplicationManager.h"
#include "../Components/Buzzer.h"

ActionAddBuzz::ActionAddBuzz(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBuzz::~ActionAddBuzz(void)
{
}

void ActionAddBuzz::Execute()
{

	UI* pUI = pManager->GetUI();


	pUI->PrintMsg("Adding a new buzzer: Click anywhere to add");


	pUI->GetPointClicked(Cx, Cy);


	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); 

	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Buzzer* pR = new Buzzer(pGInfo);
	pManager->AddComponent(pR);
}

void ActionAddBuzz::Undo()
{}

void ActionAddBuzz::Redo()
{}

