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
	//Status Compstate;
	//string Compstates;
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
	Compstates =pUI->GetString();
	while ((Compstates != "y") && (Compstates != "n"))
	{pUI->PrintMsg("Error!!! Enter 'y' for yes and 'n' for no.");
	Compstates = pUI->GetString();
	};
	if (Compstates == "y")
	{
		Compstate = ON;
		pUI->PrintMsg("Creating an on bulb");
	}
	else
	{
		Compstates = OFF;
		pUI->PrintMsg("Creating an off bulb");
	}
	Bulb* pR = new Bulb(pGInfo, bname, Compstate);
	pManager->AddComponent(pR);
}

void ActionAddBulb::Undo()
{}

void ActionAddBulb::Redo()
{}

void ActionAddBulb::ToSim() {
	//UI* pUI;
	//if (Compstate == ON) {
	//pUI->DrawBulb()
	
}