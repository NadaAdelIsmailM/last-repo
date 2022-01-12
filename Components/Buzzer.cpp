#include "Buzzer.h"
#include <iostream>
#include <string>
#include <fstream>
Buzzer::Buzzer(GraphicsInfo* r_GfxInfo)
{
}
Buzzer::Buzzer(GraphicsInfo* r_GfxInfo,string s):Component(r_GfxInfo)
{
	m_Label = s;
}

void Buzzer::Draw(UI* pUI)
{
	pUI->DrawBuzzer(*m_pGfxInfo,m_Label, selected);

}

void Buzzer::Operate()
{

}
void Buzzer::Load(string label, int value) {
	setlabel(label);
	resistance = value;


	
}

void  Buzzer::savecommponnent(fstream& file) {

	file << "Buzzer \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}

Buzzer* Buzzer::copy()
{
	Buzzer* PPr = new Buzzer(m_pGfxInfo, m_Label);

	return PPr;
}
