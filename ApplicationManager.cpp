#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddBuzzer.h"
#include "Actions\ActionAddFuse.h"
#include"Actions/ActionAddBattery.h"
#include"Actions/ActionAddSwitch.h"
#include"Actions/ActionAddGround.h"
#include"Actions/ActionAddConnection.h"
#include"Actions/ActionSelect.h"
#include"Actions/ExitAction.h"
#include"Actions/ActionSave.h"
#include"Actions/ActionLoad.h"
#include"Actions/ActionSwitchSimulation.h"
#include"Actions/ActionAddLabel.h"
#include"Actions/ActionAmmeter.h"
#include"Actions/ActionVoltmeter.h"
#include"Actions/ActionDesign.h"
#include"Actions/AddModule3.h"
#include"ActionDropDown.h"
#include"ActionPaste.h"
#include"ActionDelete.h"
//github test

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	IsSim = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
double ApplicationManager::calculateALLResistance() {
	double NetR=0;
	for (int i = 0; i < CompCount; i++) {
		NetR += CompList[i]->getResistance();
	}
	return NetR;
}
double ApplicationManager::calculateALLVoltage() {
	double NetV = 0;
	for (int i = 0; i < CompCount; i++) {
		NetV += CompList[i]->getSourceVolt();
	}
	return NetV;
}
void ApplicationManager::calculateTermsVoltage() {
	double remainingVoltage = calculateALLVoltage();
	double AllVoltage = calculateALLVoltage();
	double current;
	Component* comp1=nullptr,*ground=nullptr;
	Connection* conn1;
	int temp;
	for (int i = 0; i < CompCount; i++) {
		if (dynamic_cast<Ground*>(CompList[i])) {
			comp1 = CompList[i];
			
		}
	}
	ground = comp1;
	current = calculateALLVoltage() / calculateALLResistance();
	conn1 = comp1->getTermConnections(Term1)[0];
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
		comp1->setTerm1Voltage(0);
		comp1->setTerm2Voltage(comp1->getResistance() * current);
		break;
	case Term2:
		comp1->setTerm2Voltage(0);
		comp1->setTerm1Voltage(comp1->getResistance() * current);
		break;
	}
	pUI->GetString(to_string(comp1->getResistance() * current + AllVoltage - remainingVoltage));
	remainingVoltage -= comp1->getResistance() * current;
	while (comp1 !=ground) {

		if (conn1 == comp1->getTermConnections(Term1)[0])
			conn1 = comp1->getTermConnections(Term2)[0];
		else {
			conn1 = comp1->getTermConnections(Term1)[0];

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
			comp1->setTerm1Voltage(AllVoltage-remainingVoltage);
			comp1->setTerm2Voltage(comp1->getResistance() * current+ AllVoltage - remainingVoltage);
			break;
		case Term2:
			comp1->setTerm2Voltage(AllVoltage - remainingVoltage);
			comp1->setTerm1Voltage(comp1->getResistance() * current+ AllVoltage - remainingVoltage);
			break;
		}
		pUI->GetString(to_string(comp1->getResistance() * current + AllVoltage - remainingVoltage));
		remainingVoltage -= comp1->getResistance() * current;
		
	}
}
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}


void ApplicationManager::AddConnection(Connection* pConn) {
	ConnList[ConnCount++] = pConn;
}
void ApplicationManager::UnselectAll(Component* pComp) {
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr)
			CompList[i]->unSelected();
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr)
			ConnList[i]->unSelect();
}



/*reArrange function is used when a component and/or a connection is deleted, it sets the right actual number of components
and removes the ones that are nullptrs*/
void ApplicationManager::reArrange() {
	Component* tempCompList[MaxCompCount];	
	Connection* tempConnList[MaxConnCount];
	int counter = 0;
	for(int i=0;i<CompCount;i++)
		if (CompList[i] != nullptr) {
			tempCompList[counter] = CompList[i];
			counter++;
		}
	for (int i = 0; i < CompCount; i++) {
		CompList[i] = tempCompList[i];
		tempCompList[i] = nullptr;
		
	}
	CompCount = counter;
	counter = 0;
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			tempConnList[counter] = ConnList[i];
			counter++;
		}
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i] = tempConnList[i];
		tempConnList[i] = nullptr;
	}
	ConnCount = counter;
	
}
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
		pAct = new ActionAddRes(this);
		break;
	case ADD_BULB:
		pAct = new ActionAddBulb(this);
		break;
	case ADD_BUZZER:
		pAct = new ActionAddBuzzer(this);
		break;
	case ADD_FUSE:
		pAct = new ActionAddFuse(this);
		break;
	case ADD_BATTERY:
		pAct = new ActionAddBattery(this);
		break;
	case ADD_SWITCH:
		pAct = new ActionAddSwitch(this);
		break;
	case ADD_GROUND:
		pAct = new ActionAddGround(this);
		break;
	case ADD_CONNECTION:
		pAct = new ActionAddConnection(this);
		break;
	case ADD_Label:
		pAct = new ActionAddLabel(this);
		break;
	case SELECT:
		pAct = new ActionSelect(this);
		break;
	case SAVE:
		pAct = new ActionSave(this);
		break;
	case LOAD:
		pAct = new ActionLoad(this);
		break;
	
	case DROP_DOWN:
		pAct = new ActionDropDown(this);
		break;
	case SIM_MODE:
		pAct = new ActionSwitchSimulation(this);
		break; 
	case AMMETER:
		pAct = new ActionAmmeter(this);
		break;
	case VOLTMETER:
		pAct = new ActionVoltmeter(this);
		break;
	case DESIGNN:
		pAct = new ActionDesign(this);
		break;
	case MODULE3:
		pAct = new AddModule3(this);
		break;
	case DEL:
		pAct = new ActionDelete(this);
		break;
	//case COPY:
		//pAct = new ActionCopy(this);
		//break;
	//case PASTE:
		//pAct = new ActionPaste(this);
		//break;
	case EXIT:
		pAct = new ExitAction(this);	
		break;
	}
	
	if (pAct)
	{
		pAct->Execute();

		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	pUI->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr) {
			CompList[i]->Draw(pUI);
		}
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			ConnList[i]->Draw(pUI);
		}
	GetUI()->CreateDropDownMenu();
}
void ApplicationManager::DeleteComp(){
	for (int i = 0; i < CompCount; i++)
	{
		for (int i = 0; i < ConnCount; i++)
		{
			if (ConnList[i]->getcmp1()->isSelected() || ConnList[i]->getcmp2()->isSelected())
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
		if (CompList[i]->isSelected())
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
void ApplicationManager::DeleteConn() {
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->isSelected())
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
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit(){
	bool validation = true;
	
	////////////////////////////////////////
	if (CompCount != ConnCount|| ConnCount == 1 || ConnCount == 0)
		return false;
	else {
		///////////////////////////////////////////////
		for (int i = 0; i < CompCount; i++) {
			if (!(CompList[i]->validate()))
				return false;
		}
		int counter = 0;
		////////////////////////////////////////////
		//makes sure there is only one ground
		for (int i = 0; i < CompCount; i++) {
			if (dynamic_cast<Ground*>(CompList[i]))
				counter++;
		}
		if (counter != 1)
			return false;
		///////////////////////////////////////////
		//makes sure that there are reasonable number of connections

		for (int i = 0; i < ConnCount - 1; i++) {
			for (int j = i + 1; j < ConnCount; j++) {
				if (!(ConnList[i]->validate(ConnList[j])))
					return false;
			}
		}

		/// ////////////////////////////////////////
		
		Connection* conn1;
		Component* comp1;
		counter = 0;
		int temp;
		for (int i = 0; i < CompCount; i++) {

			comp1 = CompList[i];

			conn1 = comp1->getTermConnections(Term1)[0];
			temp = conn1->WhatComp(CompList[i]);
			switch (temp) {
			case 1:
				comp1 = conn1->getComp(2);
				break;
			case 2:
				comp1 = conn1->getComp(1);
			}
			counter = 1;
			//for (int j = 0; j < CompCount - 1; j++) 
			while (comp1 != CompList[i]&& counter <= CompCount) {
			
				if (conn1 == comp1->getTermConnections(Term1)[0])
					conn1 = comp1->getTermConnections(Term2)[0];
				else {
					conn1 = comp1->getTermConnections(Term1)[0];

				}
				temp = conn1->WhatComp(comp1);
				switch (temp) {
				case 1:
					comp1 = conn1->getComp(2);
					break;
				case 2:
					comp1 = conn1->getComp(1);
				}
				counter++;
				
			}

			if (counter != CompCount)
				return false;
		}
		////////////////////////////////////////////
		return validation;
	}
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
			x1 = ConnList[i]->getgraphics()->PointsList[0].x;
			x2 = ConnList[i]->getgraphics()->PointsList[1].x;
			y1 = ConnList[i]->getgraphics()->PointsList[0].y;
			y2 = ConnList[i]->getgraphics()->PointsList[1].y;
			slope = ConnList[i]->SlopeofLine();
			
			for(int j=-5;j<=5;j++) {
		//so when the click is more >x1 && >x2
			//if the line is vertical
				if ((x + j >= x2 && x + j <= x1) || (x + j >= x1 && x + j <= x2)) {
					for (int k = -4; k <= 4; k++){
						if(x1!=x2){
						right = slope*(x - (x1+k));
						left = y - (y1 + k);}
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
//void ApplicationManager::Save(fstream& file, string name)
//{
void ApplicationManager::SaveCircuit(ofstream& CircuitFile)
{
	CircuitFile << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
		CompList[i]->SaveCircuit(CircuitFile);
	Component::resetID();
	CircuitFile << "Connections \n" << CompCount << endl;
	for (int i = 0; i < ConnCount; i++) {
		int comp1 = getCompOrder(ConnList[i]->getComp(1)) + 1;
		int comp2 = getCompOrder(ConnList[i]->getComp(2)) + 1;
		ConnList[i]->save(CircuitFile, comp1, comp2);
	}
}
	
int ApplicationManager::getCompOrder(Component* comp) {
	for (int i = 0; i < CompCount; i++) {
		if (comp == CompList[i])
			return i;
	}
}
void ApplicationManager::Load2(ifstream& my_file, string fo_name) {
	GraphicsInfo* G = new GraphicsInfo(2);
	if (!my_file) {
		pUI->PrintMsg("File not found");
	}

	else {
		my_file.open((fo_name));
		int num;
		my_file >> num;
		string cmpname;
		for (int i = 0; i < num; i++)
		{

			string Label;
			int ginfoX, ginfoY, ID, Value;
			//if (my_file.good()) {

			my_file >> cmpname;
			my_file >> ID;
			my_file >> Label;
			my_file >> Value;
			my_file >> ginfoX >> ginfoY;
			GraphicsInfo* GI = new GraphicsInfo(2);
			GI->PointsList[0].x = ginfoX;
			GI->PointsList[0].y = ginfoY;
			GI->PointsList[1].x = ginfoX + pUI->getCompWidth();;
			GI->PointsList[1].y = ginfoY + pUI->getCompHeight();

			if (cmpname == "RES") {
				Resistor* comp = new Resistor(GI);
				comp->Load2(Value, Label);
				AddComponent(comp);
			}
			if (cmpname == "SWT") {
				Switch* comp = new Switch(GI);
				comp->Load2(Value, Label);
				AddComponent(comp);
			}
			if (cmpname == "BAT") {
				Battery* comp = new Battery(GI);
				comp->Load2(Value, Label);
				AddComponent(comp);
			}
			if (cmpname == "BLB") {
				Bulb* comp = new Bulb(GI);
				comp->Load2(Value, Label);
				AddComponent(comp);
			}
			if (cmpname == "GND") {
				Ground* comp = new Ground(GI);
				comp->Load2(Value, Label);
				AddComponent(comp);
			}
			if (cmpname == "FUS") {
				Fuse* comp = new Fuse(GI);
				comp->Load2(Value, Label);
				AddComponent(comp);
			}
			if (cmpname == "BZR") {
				Buzzer* comp = new Buzzer(GI);
				comp->Load2(Value, Label);
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
			R->Load2(CompList[comp1 - 1], CompList[comp2 - 1]);
			AddConnection(R);

		}

	}

}
////////////////////////////////////////////////////////////////////
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		// TODO
	}
	else {
		this->IsSim = true;
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		//CalculateVolt(current);
	}
}
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	// TODO
	return calculateALLVoltage() / calculateALLResistance();
}



////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	for (int i = 0; i < ConnCount; i++)
		delete ConnList[i];
	delete pW;
	delete pUI;
}