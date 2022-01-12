#include "Bulb.h"
#include <iostream>
#include <string>
#include <fstream>
Bulb::Bulb(GraphicsInfo* r__GfxInfor)
{
}

Bulb::Bulb(GraphicsInfo* r__GfxInfo,string bname,Status IsOn):Component(r__GfxInfo) {
	if (Compstate=OFF) {
		IsOn = OFF;
	}
	else {
		IsOn = ON;
	}
	m_Label = bname;
}
/*Bulb::Bulb(GraphicsInfo* r_GfxInfo, bool IsOn)
{
	this->IsOn = IsOn;
}*/

void Bulb::Draw(UI* pUI)
{

	//pUI->DrawBulb(*m_pGfxInfo,IsSelected);
	pUI->DrawBulb(*m_pGfxInfo,m_Label, selected, IsOn);



}

void Bulb::Operate()
{

}
void Bulb::Load(string label, int value) {
	resistance = value;
	setlabel(label);
}
void  Bulb::savecommponnent(fstream& file) {

	file << "Bulb \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}
