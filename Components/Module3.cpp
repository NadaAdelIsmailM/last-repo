#include "Module.h"
Module::Module(GraphicsInfo* r_GfxInfo)
{
	resistance = 1;


}
Module::Module(GraphicsInfo* r_GfxInfo, string sname) :Component(r_GfxInfo) {

}

Module::Draw(UI* pUI) {
	pUI->DrawModule(*m_pGfxInfo, value, selected)const
}