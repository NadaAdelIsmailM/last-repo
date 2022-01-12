#include "Switch.h"
#include <iostream>
#include <string>
#include <fstream>

Switch::Switch(GraphicsInfo* r_GfxInfo)
{
}
Switch::Switch(GraphicsInfo* r_GfxInfo,string sname) :Component(r_GfxInfo)
{
	m_Label = sname;
}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass switch drawing info to it.
	int xl = m_pGfxInfo->PointsList[0].x;
	int yl = m_pGfxInfo->PointsList[0].y + 50;
	pUI->labelMsg(getlabel(), xl, yl);
	if (Compstate == ON)
		pUI->DrawOpenedSwitch(*m_pGfxInfo, m_Label, selected);
	else
		pUI->DrawClosedSwitch(*m_pGfxInfo, m_Label, selected); //update to draw switch

}//void Switch::ToSim() {
	/*UI* pUI;
	if (isSelected) {
		if (Compstate == ON) { pUI->DrawClosedSwitch(*m_pGfxInfo, m_Label, false); }
		else { pUI->DrawOpenedSwitch(*m_pGfxInfo, m_Label, false); }
	}*/


void Switch::Operate()
{
}
void  Switch::savecommponnent(fstream& file) {

	file << "Switch \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}

void Switch::Load(string label, int value) {
	if (value == 0)
		Compstate = ON;
	else
		Compstate = OFF;
	setlabel(label);
}