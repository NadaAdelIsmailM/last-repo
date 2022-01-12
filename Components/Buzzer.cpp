#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo):Component(r_GfxInfo)
{}

void Buzzer::Draw(UI* pUI)
{
	pUI->DrawBuzzer(*m_pGfxInfo,this->selected);

}

void Buzzer::Operate()
{

}
