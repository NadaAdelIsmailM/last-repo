#include "ActionAddBattery.h"
#include "..\ApplicationManager.h"
#include "..\Components\Battery.h"


ActionAddBattery::ActionAddBattery(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBattery::~ActionAddBattery(void)
{
}

void ActionAddBattery::Execute()
{

	//Get a Pointer to the user Interfaces

	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Add the label of the battery");
	bname = pUI->GetString();
	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	
	pUI->PrintMsg("enter the volt of the battery");
	
	vol = pUI->GetString();   //get the voltage of the battery 
	//double volt = stod(vol);
	pUI->ClearStatusBar();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Battery* pB = new Battery(pGInfo,bname);
	pManager->AddComponent(pB);
}

void ActionAddBattery::Undo()
{}

void ActionAddBattery::Redo()
{}
//void ToSim(){}