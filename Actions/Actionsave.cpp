#include "Actionsave.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include <fstream>

Actionsave::Actionsave(ApplicationManager* pApp) :Action(pApp)
{
}

Actionsave::~Actionsave(void)
{
}

void Actionsave::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("save !!");
	file.open("saved_file1.txt", ios::app);
	pManager->savefilecommponent(file);
	pManager->savefilrconnection(file);
	//Get Center point of the area where the Comp should be drawn

}

void Actionsave::Undo() {

}

void Actionsave::Redo() {

 }

