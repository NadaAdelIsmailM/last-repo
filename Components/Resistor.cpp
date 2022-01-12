#include "Resistor.h"
#include <iostream>
#include <string>
#include <fstream>
Resistor::Resistor() {
	
}

Resistor::Resistor(GraphicsInfo* r_GfxInfo)
{
}

Resistor::Resistor(GraphicsInfo *r_GfxInfo,string b):Component(r_GfxInfo)
{
	this->resistance = resistance;
	m_Label = b;
}


void Resistor::Draw(UI* pUI)
{	
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo,m_Label, selected); //update to draw resistor

}

void Resistor::Operate()
{

}
void Resistor::Load(string label, int value) {
	resistance = value;
	setlabel(label);
}

void  Resistor::savecommponnent(fstream& file) {

	file << "Resistor  \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}

Resistor* Resistor::copy()
{
	Resistor* PPr = new Resistor(m_pGfxInfo, m_Label);
	this->resistance = resistance;
	return PPr;
}
