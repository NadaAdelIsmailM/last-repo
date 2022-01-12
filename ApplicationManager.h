#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include <iostream>
#include <fstream>
#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components/Component.h"
#include "Components/Connection.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200
	};	//Max no of Components	

private:
	bool IsSimulation;
	int CompCount;//Actual number of Components
	int ConnCount;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxCompCount];
	UI* pUI; //pointer to the UI
	Component* x;


public:	
	Component* copycomp;
	void setx(Component* x);
	Component* getx();
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	void  savefilecommponent(fstream& file);

	//Gets a pointer to UI Object
	UI* GetUI();
	
	double getNetResistance();
	double getNetVoltage();
	void getTermVoltage();
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void AddConnection(Connection* pConn);
	void UnselectAll();
	bool ValidConnectionPoint(int x, int y,const Component* c1);
	void Load2(ifstream &my_file, string fo_name);
	Component* GetComponentByCoordinates(int x, int y);
	Connection* GetConnByCoordinates(int x, int y);
	void ToSimulation();
	double CalculateCurrent();
	void CalculateVolt(double current);
	void savefilrconnection(fstream& file);
	void paste();
	void setcopycomponent(Component* clicked);
	Component* ApplicationManager::getcopycomponent();
	//destructor

	~ApplicationManager();
};

#endif