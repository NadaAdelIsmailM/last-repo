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
	pUI->DrawSwitch(*m_pGfxInfo,m_Label); //update to draw switch

}

void Switch::Operate()
{
}
void  Switch::savecommponnent(fstream& file) {

	file << "Switch \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}

void Switch::setswitch(string on)
{
	switch_s = on;
}

bool Switch::is_closed() {
	if (switch_s == "closed") {
		return true;
	}
	else return false;
}

void Switch::Load(string label, int value) {
	if (value == 0)
		CompStatus = false;
	else
		CompStatus = true;
	setlabel(label);
}