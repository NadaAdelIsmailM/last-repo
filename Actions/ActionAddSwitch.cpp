#include "ActionAddSwitch.h"
#include "../ApplicationManager.h"

ActionAddSwitch::ActionAddSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddSwitch::~ActionAddSwitch(void)
{

}

void ActionAddSwitch::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("enter a label ");
	string sname = pUI->GetString();
	pUI->ClearStatusBar();
	//Get Center point of the area where the Comp should be drawn

	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar

	//pUI->PrintMsg("value");
	//string value = pUI->GetString();
	//pUI->ClearStatusBar();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Switch* pR = new Switch(pGInfo,sname);
	pUI->PrintMsg("Enter state of switch, 0=closed& 1=opened");
	string value = pUI->GetString();
	if (value != "1" && value != "0")
		value = "1";
	pR->setState(stod(value));


 
	pUI->ClearStatusBar();
	pManager->AddComponent(pR);
}


void ActionAddSwitch::Undo()
{}

void ActionAddSwitch::Redo()
{}
