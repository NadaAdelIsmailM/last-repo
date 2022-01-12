#include "fuse.h"

fuse::fuse(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void fuse::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo,this->selected); //update to draw resistor

}

void fuse::Operate()
{

}