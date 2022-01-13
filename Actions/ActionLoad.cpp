#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "ActionAddRes.h"

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{
}

void ActionLoad::Execute()
{

	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Enter the name of file you want to open");


	string f_name = pUI->GetString() + ".txt";

	//Clear Status Bar
	pUI->ClearStatusBar();
	ifstream myfile;
	//string fo_name = f_name + ".txt";
	//my_file.open((f_name));

	pManager->Load2(myfile, f_name);

}

void ActionLoad::Undo()
{}

void ActionLoad::Redo()
{}