 #ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include<fstream>
#include<iosfwd >
#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { 
		MaxCompCount = 200,
		MaxConnCount = 1000	};	//Max no of components and connectors


private:

	bool IsSim; // true when in simulation mode
	bool IsSeries;
	int CompCount;		//Actual number of Components
	int ConnCount;		//Actual number of Connections
	int drawningpenwidth;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount];	//List of all Connections (Array of pointers)
	window* pW;
	UI* pUI; //pointer to the UI
	bool state;

public:
	bool getswitchstate() {
		return state;
	}
	void setswitchstate(bool s) {
		state = s;
	}
	Component* copycomp;
	void setx(Component* x);
	Component* getx();

	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	
	double calculateALLResistance();
	double calculateALLVoltage();
	void calculateTermsVoltage();
	void AddComponent(Component* pComp); //Adds a new component to the list of components
	void AddConnection(Connection* pConn);//Adds a new connection to the list of connection
	void DelSelected();//deletes all components/connections that are selected by the user, can be more than one at once
	void UnselectAll(Component* pComp);
	void UnselectAll(Connection* pConn);
	void reArrange();//description the in the implementation
	Component* GetComponentByCoordinates(int x, int y); //returns pointer to the component if (x,y) is in the component region
	Connection* GetConnByCoordinates(int x, int y);//returns pointer to the connection if (x,y) is in the component region
	void SaveCircuit(ofstream& file);
	int ApplicationManager::getCompOrder(Component* comp);//returns the index of the component in CompList
	void Load2(ifstream& my_file, string fo_name);
				// Simulation Mode Functions //
	bool ValidateCircuit();
	void ToSimulation(); // Switches to simulation mode
	double CalculateCurrent();
	void CalculateVolt(double current);
	void savefilrconnection(fstream& file);
	void paste();
	void setcopycomponent(Component* clicked);
	Component* ApplicationManager::getcopycomponent();
	void DeleteComp();
	void DeleteConn();
	//destructor

	~ApplicationManager();
};

#endif