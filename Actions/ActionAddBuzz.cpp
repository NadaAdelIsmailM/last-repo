#include "ActionAddBuzz.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

ActionAddBuzz::ActionAddBuzz(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBuzz::~ActionAddBuzz(void)
{
}

void ActionAddBuzz::Execute()
{


	UI* pUI = pManager->GetUI();


	pUI->PrintMsg("Add label to the buzzer");
	zname = pUI->GetString();


	pUI->GetPointClicked(Cx, Cy);


	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Buzzer* pR = new Buzzer(pGInfo, zname);
	pManager->AddComponent(pR);
}

void ActionAddBuzz::Undo()
{}

void ActionAddBuzz::Redo()
{}

