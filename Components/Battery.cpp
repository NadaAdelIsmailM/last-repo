#include "Battery.h"

Battery::Battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo,this->selected); //update to draw resistor

}

void Battery::Operate()
{

}