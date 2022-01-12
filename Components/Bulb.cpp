#include "Bulb.h"
#include <iostream>
#include <string>
#include <fstream>
Bulb::Bulb(GraphicsInfo* r__GfxInfor)
{
}
Bulb::Bulb(GraphicsInfo* r__GfxInfo,string bname):Component(r__GfxInfo) {
	
	m_Label = bname;
}
/*Bulb::Bulb(GraphicsInfo* r_GfxInfo, bool IsOn) : Resistor(r_GfxInfo)
{
	this->IsOn = IsOn;
}*/

void Bulb::Draw(UI* pUI)
{

	//pUI->DrawBulb(*m_pGfxInfo,IsSelected);
	pUI->DrawBulb(*m_pGfxInfo,m_Label, selected);



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

Bulb* Bulb::copy()
{
	Bulb* PPr = new Bulb(m_pGfxInfo, m_Label);

	return PPr;
}
