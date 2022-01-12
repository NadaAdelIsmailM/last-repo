#include "Components/Module3.h"

Module::Module(GraphicsInfo* r_GfxInfo)
{
	resistance = 1;
	//sourceVoltage = 0;

}

Module::Module(GraphicsInfo* r_GfxInfo, string sname) :Component(r_GfxInfo) {
	resistance = 1;
}
void Module::Draw(UI* pUI) {
	pUI->DrawModule(*m_pGfxInfo,m_Label, selected);
}
void Module::Load(string label, int value) {
	resistance = value;
	setlabel(label);
}
void Module::Operate() {

}
void Module::savecommponnent(fstream& file) {
}
//void Module::ToSim() {}