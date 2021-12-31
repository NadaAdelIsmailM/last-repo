#include "Load.h"
#include "../ApplicationManager.h"


Load::Load(ApplicationManager* pApp) :Action(pApp) {
	
}


void Load::Execute(){
	

	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Enter the name of file you want to open");

	
	string f_name = pUI->GetString() + ".txt";

	//Clear Status Bar
	pUI->ClearStatusBar();
	ifstream myfile;
	//string fo_name = f_name + ".txt";
	//my_file.open((f_name));
	
	pManager->Load2(myfile,f_name);
	
	//my_file.close();

}
Load::~Load() {

}
void Load::Undo() {

}
void Load::Redo() {

}