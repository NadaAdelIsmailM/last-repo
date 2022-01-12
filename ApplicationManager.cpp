#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include"Actions/ActionAddBuzz.h"
#include"Actions/ActionAddBulb.h "
#include"Actions/ActionAddConnec.h "
#include"Actions/ActionAddBattery.h"
#include"Actions/ActionAddGround.h"
#include"Actions/ActionAddfuse.h"
#include"Actions/ActionAddSwitch.h"
#include "Actions/Load.h"
#include"Actions/ActionAddConnec.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionSwitchActual.h"
#include "Actions/ActionSwitchSim.h"
#include "Actions/ActionDesign.h"
#include "Actions/ActionSave.h"


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;
	IsSimulation = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}

//////
// 
double ApplicationManager::getNetResistance() {
	double NetR = 0;
	for (int i = 0; i < CompCount; i++) {
		NetR += CompList[i]->getResistance();
	}
	return NetR;
}
double ApplicationManager::getNetVoltage() {
	double NetV = 0;
	for (int i = 0; i < CompCount; i++) {
		NetV += CompList[i]->getSourceVoltage();
	}
	return NetV;
}
void ApplicationManager::getTermVoltage() {
	double remainingVoltage = getNetVoltage();
	double AllVoltage = getNetVoltage();
	double current;
	Component* comp1 = nullptr, * ground = nullptr;
	Connection* conn1;
	int temp;
	for (int i = 0; i < CompCount; i++) {
		if (dynamic_cast<Ground*>(CompList[i])) {
			comp1 = CompList[i];

		}
	}
	ground = comp1;
	current = getNetVoltage() / getNetResistance();
	conn1 = comp1->getTermConn(Term1)[0];
	temp = conn1->WhatComp(comp1);
	switch (temp) {
	case 1:
		comp1 = conn1->getComp(2);
		break;
	case 2:
		comp1 = conn1->getComp(1);
	}
	switch (comp1->WhatTerminal(conn1)) {
	case Term1:
		comp1->setTermi1Volt(0);
		comp1->setTermi2Volt(comp1->getResistance() * current);
		break;
	case Term2:
		comp1->setTermi2Volt(0);
		comp1->setTermi1Volt(comp1->getResistance() * current);
		break;
	}
	pUI->GetString(to_string(comp1->getResistance() * current + AllVoltage - remainingVoltage));
	remainingVoltage -= comp1->getResistance() * current;
	while (comp1 != ground) {

		if (conn1 == comp1->getTermConn(Term1)[0])
			conn1 = comp1->getTermConn(Term2)[0];
		else {
			conn1 = comp1->getTermConn(Term1)[0];

		}
		temp = conn1->WhatComp(comp1);
		switch (temp) {
		case 1:
			comp1 = conn1->getComp(2);
			break;
		case 2:
			comp1 = conn1->getComp(1);
		}
		switch (comp1->WhatTerminal(conn1)) {
		case Term1:
			comp1->setTermi1Volt(AllVoltage - remainingVoltage);
			comp1->setTermi2Volt(comp1->getResistance() * current + AllVoltage - remainingVoltage);
			break;
		case Term2:
			comp1->setTermi2Volt(AllVoltage - remainingVoltage);
			comp1->setTermi1Volt(comp1->getResistance() * current + AllVoltage - remainingVoltage);
			break;
		}
		pUI->GetString(to_string(comp1->getResistance() * current + AllVoltage - remainingVoltage));
		remainingVoltage -= comp1->getResistance() * current;

	}
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


//////////////////
void ApplicationManager::UnselectAll() {
	for (int i = 0; i < CompCount; i++) {
			CompList[i]->unSelect();
	}
	for (int i = 0; i < ConnCount; i++)
			ConnList[i]->unSelect();
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
		case LOAD:
			pAct = new Load(this);
			break;
		case SELECT:
			pAct = new ActionSelect(this);
			break;
		case DESIGGN:
			pAct = new ActionDesign(this);
			break;
		case SIM_MODE:
			pAct = new ActionSwitchSim(this);
			break;
		case DSN_MODE:
			pAct = new ActionSwitchActual(this);
			break;
		case SAVE:
			pAct = new Actionsave(this);
			break;



		case EXIT:
			pAct = new ActionExit(this);
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
Component* ApplicationManager::GetComponentByCoordinates(int x, int y) {
	UI* pUI = GetUI();
	int  isExist = 0;
	int ydifference, xdifference;
	int compheight = pUI->getCompHeight();
	int compwidth = pUI->getCompWidth();
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			ydifference = abs(y - CompList[i]->getCompCenterY(pUI));
			xdifference = abs(x - CompList[i]->getCompCenterX(pUI));
			if ((ydifference <= compheight / 2) && (xdifference <= compwidth / 2)) {
				isExist = 1;
				return CompList[i];

				break;
			}

		}
	}
	if (isExist == 0)
		return nullptr;
}

Connection* ApplicationManager::GetConnByCoordinates(int x, int y) {
	//i hope there is a better way to implement this
	UI* pUI = GetUI();
	int  isExist = 0;
	int x1;
	int x2;
	int y1;
	int y2;
	double slope;
	int right, left;
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr) {
			x1 = ConnList[i]->getGraphics()->PointsList[0].x;
			x2 = ConnList[i]->getGraphics()->PointsList[1].x;
			y1 = ConnList[i]->getGraphics()->PointsList[0].y;
			y2 = ConnList[i]->getGraphics()->PointsList[1].y;
			slope = ConnList[i]->SlopeofLine();

			for (int j = -5; j <= 5; j++) {
				/*this loop is for when the click is more >x1 && >x2
								if the line the somewhat vertical*/
				if ((x + j >= x2 && x + j <= x1) || (x + j >= x1 && x + j <= x2)) {
					for (int k = -4; k <= 4; k++) {
						/*while the reason for this loop is that the user
		click is never exactly on the line equation so it checks if it is on any other near parallel line*/
						if (x1 != x2) {
							right = slope * (x - (x1 + k));
							left = y - (y1 + k);
						}
						else {
							right = x - (x1 + k);
							left = 0;
						}
						if (left == right) {
							return ConnList[i];
							isExist = 1;
							break;
						}
					}
				}
			}

		}
	}
	if (isExist == 0)
		return nullptr;
}



void ApplicationManager::savefilrconnection(fstream& file) {
	for (int i = 0;i < ConnCount;i++) {
		ConnList[i]->saveconnection(file);
	}
}

void  ApplicationManager::savefilecommponent(fstream& file) {
	for (int i = 0;i < CompCount;i++) {
		CompList[i]->savecommponnent(file);
	}
}

bool ApplicationManager::ValidConnectionPoint(int x, int y, const Component* c1)  {
	int c = 0;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->IsInRegion(x, y)) {
			c1 = CompList[i];
			c++;
		}
	}
	if (c > 0)
		return true;	
	else
		return false;
	
	
}
/*
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		// TODO
	}
	else {
		this->IsSimulation = true;
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		CalculateVolt(current);
	}
}*/
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	// TODO
	return getNetVoltage() / getNetResistance();
}

// Calculates voltage at each component terminal
void ApplicationManager::CalculateVolt(double current) {
	// TODO
}




void ApplicationManager::Load2(ifstream& my_file, string fo_name) {
	GraphicsInfo* G = new GraphicsInfo(2);

	//string f_name = pUI->GetSrting();
	//my_file.open((f_name, ".txt"), ios::in);
	if (!my_file) {
		pUI->PrintMsg("File not found");
		
		//pUI->ClearStatusBar();
	}

	else {
		my_file.open((fo_name));
		int num;
		my_file >> num;
		string cmpname;
		for (int i = 0; i < num; i++)
		{

			string label;
			int ginfoX, ginfoY, ID, value;
			//if (my_file.good()) {

			my_file >> cmpname;
			my_file >> ID;
			my_file >> label;
			my_file >> value;
			my_file >> ginfoX >> ginfoY;
			GraphicsInfo* GI = new GraphicsInfo(2);
			GI->PointsList[0].x = ginfoX;
			GI->PointsList[0].y = ginfoY;
			GI->PointsList[1].x = ginfoX + pUI->getCompWidth();;
			GI->PointsList[1].y = ginfoY + pUI->getCompHeight();

			if (cmpname == "RES") {
				Resistor* comp = new Resistor(GI);
				comp->Load(label, value);
				AddComponent(comp);
			}
			if (cmpname == "SWT") {
				Switch* comp = new Switch(GI);
				comp->Load(label, value);
				AddComponent(comp);
			}
			if (cmpname == "BAT") {
				Battery* comp = new Battery(GI);
				comp->Load(label, value);
				AddComponent(comp);
			}
			if (cmpname == "BLB") {
				Bulb* comp = new Bulb(GI);
				comp->Load(label, value);
				AddComponent(comp);
			}
			if (cmpname == "GND") {
				Ground* comp = new Ground(GI);
				comp->Load(label, value);
				AddComponent(comp);
			}
			if (cmpname == "FUZ") {
				fuse* comp = new fuse(GI);
				comp->Load(label, value);
				AddComponent(comp);
			}
			if (cmpname == "BZR") {
				Buzzer* comp = new Buzzer(GI);
				comp->Load(label, value);
				AddComponent(comp);
			}
		}
		int num2;
		my_file >> cmpname;
		my_file >> num2;
		for (int i = 0; i < num2; i++)
		{

			

			int comp1, comp2, gpoints;
			my_file >> comp1;

			my_file >> comp2;
			my_file >> gpoints;
			GraphicsInfo* GI = new GraphicsInfo(2);
			GI->PointsList[0].x = gpoints;
			my_file >> gpoints;
			GI->PointsList[0].y = gpoints;
			my_file >> gpoints;
			GI->PointsList[1].x = gpoints;
			my_file >> gpoints;
			GI->PointsList[1].y = gpoints;
			Connection* R = new Connection(GI);

			R->Load(CompList[comp1 - 1], CompList[comp2 - 1]);
			AddConnection(R);

		}

	}

}


	
