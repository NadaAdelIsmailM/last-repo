#include "ActionAddConnec.h"
#include "..\ApplicationManager.h"
#include "../Components/Connection.h"

ActionAddConnec::ActionAddConnec(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddConnec::~ActionAddConnec(void)
{
}

void ActionAddConnec::Execute()
{
	Component* cmp1=nullptr;
	Component* cmp2=nullptr;
	UI* pUI = pManager->GetUI();

	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	pUI->PrintMsg("Adding a new connection: Click on the first component");
	
	pUI->GetPointClicked(x1, y1);
	cmp1 = pManager->ValidPoint(x1, y1);
	while (cmp1==nullptr)
	{
		pUI->PrintMsg("Error!!! Invalid Connection point. Click agian to add first connection point.");
		pUI->GetPointClicked(x1, y1);

	};
	pGInfo->PointsList[0].x = x1;
	pGInfo->PointsList[0].y = y1;
	
	pUI->PrintMsg("Adding a new connection: Click on the Second component");
	pUI->GetPointClicked(x2,y2);
	cmp2 = pManager->ValidPoint(x2, y2);
	while (cmp2 == nullptr)
	{
		pUI->PrintMsg("Error!!! Invalid Connection point. Click agian to add second connection point.");
		pUI->GetPointClicked(x1, y1);

	};
	pGInfo->PointsList[1].x = x2;
	pGInfo->PointsList[1].y = y2;
	/*
	if (x1 > x2) {
		pGInfo->PointsList[0].x = cmp1->m_pGfxInfo->PointsList[0].x;
		pGInfo->PointsList[1].x = cmp2->m_pGfxInfo->PointsList[1].x;

	}
	else if (x1<x2) {
		pGInfo->PointsList[0].x = cmp1->m_pGfxInfo->PointsList[1].x;
		pGInfo->PointsList[1].x = cmp2->m_pGfxInfo->PointsList[0].x;
	}
	if (y1 > y2) {
		pGInfo->PointsList[0].y = cmp1->m_pGfxInfo->PointsList[0].y;
		pGInfo->PointsList[1].y = cmp2->m_pGfxInfo->PointsList[1].y;

	}
	else if (x1 < x2) {
		pGInfo->PointsList[0].y = cmp1->m_pGfxInfo->PointsList[1].y;
		pGInfo->PointsList[1].y = cmp2->m_pGfxInfo->PointsList[0].y;
	}*/

	pUI->ClearStatusBar();

	Connection* pR = new Connection(pGInfo,cmp1,cmp2);
	pManager->AddConnection(pR);
}

void ActionAddConnec::Undo()
{}

void ActionAddConnec::Redo()
{}

