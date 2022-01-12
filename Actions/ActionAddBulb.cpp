#include "ActionAddBulb.h"
#include "..\ApplicationManager.h"
#include "../Components/Bulb.h"
ActionAddBulb::ActionAddBulb(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBulb::~ActionAddBulb(void)
{
}

void ActionAddBulb::Execute()
{
	bool addIsOn;
	string addIsOnS;
	UI* pUI = pManager->GetUI();


	pUI->PrintMsg("enter the label of the bulb");
	string bname=pUI->GetString();
	pUI->ClearStatusBar();
	pUI->GetPointClicked(Cx, Cy);


	pUI->ClearStatusBar();

	
	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;
	pUI->PrintMsg("Is the bulb on or off? <y/n>");
	addIsOnS=pUI->GetString();
	while ((addIsOnS != "y") && (addIsOnS != "n")) 
	{pUI->PrintMsg("Error!!! Enter 'y' for yes and 'n' for no.");
	addIsOnS = pUI->GetString();
	};
	if (addIsOnS == "y")
	{
		addIsOn = true;
		pUI->PrintMsg("Creating an on bulb");
	}
	else
	{
		addIsOn = false;
		pUI->PrintMsg("Creating an off bulb");
	}
	Bulb* pR = new Bulb(pGInfo,bname);
	pManager->AddComponent(pR);
}

void ActionAddBulb::Undo()
{}

void ActionAddBulb::Redo()
{}

