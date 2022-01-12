#include "AddModule.h"
#include"ApplicationManager.h"
#include"UI/UI.h"
AddModule::AddModule(ApplicationManager* pApp) :Action(pApp)
{
}

AddModule::~AddModule(void)
{
}

void AddModule::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Adding new module: Click anywhere to add");

	/*pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > UI::getToolBarHeight() + UI::getCompHeight() / 2
		&& Cy < UI::Height() - UI::getStatusBarHeight() - UI::getCompHeight() / 2
		&& Cx > UI::getCompWidth() / 2
		&& Cx < UI::getWidth() - UI::getCompWidth() / 2)) {
		pUI->GetPointClicked(Cx, Cy);*/

}

void AddModule::Undo()
{

}

void AddModule::Redo()
{}