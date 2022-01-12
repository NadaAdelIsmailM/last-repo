#include "AddModule.h"
AddModule::AddModule(ApplicationManager* pApp) :Action(pApp)
{
}

AddModule::~AddModule(void)
{
}

void AddModule::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Click anywhere to Add Module");
	pUI->GetPointClicked(Cx, Cy);
	pUI->ClearStatusBar();
	GraphicsInfo* pGInfo = new GraphicsInfo(2);//constructor

	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Module* pM = new Module(pGInfo);
	string value[10];
	for (int i = 0; i < 10; i++) {
		pUI->PrintMsg("Enter Resistance value ");
		value[i] = pUI->GetString();
	}
	double R1 = 1.0 / (stod(value[0]) + stod(value[1]));
	double R2 = 1.0 / (stod(value[2]) + stod(value[3]));
	double R3 = 1.0 / (stod(value[4]) + stod(value[1]));
	double R4 = 1.0 / (stod(value[6]) + stod(value[3]));
	double R5 = 1.0 / (stod(value[8]) + stod(value[1]));
	int R = 1 / (R1 + R2 + R3 + R4 + R5);

	pM->setResistance(R);
	pUI->ClearStatusBar();


	pManager->AddComponent(pM);
}

void AddModule::Undo()
{

}

void AddModule::Redo()
{}