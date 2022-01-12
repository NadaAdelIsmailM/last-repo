#include "Battery.h"
#include <iostream>
#include <string>
#include <fstream>
Battery::Battery(GraphicsInfo* r_GfxInfo)
{
}
Battery::Battery(GraphicsInfo* r_GfxInfo,string bname) :Component(r_GfxInfo)
{
	m_Label = bname;
}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo,m_Label); //update to draw resistor

}

void Battery::Operate()
{

}
void  Battery::savecommponnent(fstream& file) {

	file << "Switch \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}

void Battery::Load(string label, int value) {
	setlabel(label);
	//resistance = value;



}

Battery* Battery::copy()
{
	Battery* PPr = new Battery(m_pGfxInfo, m_Label);

	return PPr;
}
