#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include"Actions/ActionAddBuzz.h"
#include"Actions/ActionAddBulb.h "
#include"Actions/ActionAddConnec.h "
#include"Actions/ActionAddBattery.h"
#include"Actions/ActionAddGround.h"
#include"Actions/ActionAddfuse.h"
#include"Actions/ActionAddSwitch.h"
#include"Actions/ActionSelectComponent.h"
#include"Actions/ActionDeleteComponent.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
void ApplicationManager::AddConnection(Connection* pConn)
{
	ConnList[ConnCount++] = pConn;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case ADD_LAMP:
			pAct = new ActionAddBulb(this);
			break;		
		case ADD_BATTERY:
			pAct = new ActionAddBattery(this);
			break;
		case ADD_SWITCH:
			pAct = new ActionAddSwitch(this);
			break;
		case ADD_GRND:
			pAct = new ActionAddGround(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuzz(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddfuse(this);
			break;
		case ADD_CONNECTION:
			pAct = new ActionAddConnec(this);
			break;
		case SELECT:
			pAct = new ActionSelectComponent(this);
			break;
		case DEL:
			pAct = new ActionDeleteComponent(this);
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);
		for(int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pUI);

}

void ApplicationManager::DeleteComp()
{
	
	for (int i = 0; i < CompCount; i++)
	{
		for (int i = 0; i < ConnCount; i++)
		{
			if (ConnList[i]->getcmp1()->IsSelected() || ConnList[i]->getcmp2()->IsSelected())
			{
				pUI->ClearDrawingArea();
				delete ConnList[i];
				ConnList[i] = nullptr;
				for (int j = i; j < ConnCount - 1; j++)
				{
					ConnList[j] = ConnList[j + 1];
				}
				i--;
				ConnCount--;
			}
		}
		if (CompList[i]->IsSelected())
		{
			pUI->ClearDrawingArea();
			delete CompList[i];
			CompList[i] = nullptr;
			for (int j = i; j < CompCount - 1; j++)
			{
				CompList[j] = CompList[j + 1];
			}
			i--;
			CompCount--;
		}
	}
}

void ApplicationManager::DeleteConn()
{
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->IsSelected())
		{
			pUI->ClearDrawingArea();
			delete ConnList[i];
			ConnList[i] = nullptr;
			for (int j = i; j < ConnCount - 1; j++)
			{
				ConnList[j] = ConnList[j + 1];
			}
			i--;
			ConnCount--;
		}
	}
}
////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}


////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	for (int i = 0; i < ConnCount; i++)
		delete ConnList[i];
	delete pUI;
	
}

Component* ApplicationManager::ValidPoint(int x, int y)  {
	
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->IsInRegion(x, y)) {
			return CompList[i];
		}
 
	}
 return nullptr;

}