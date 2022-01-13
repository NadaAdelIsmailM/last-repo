#include"Bulb.h"
Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;
	pUI->labelMsg(getLabel(), xlabel, ylabel);
	pUI->DrawBulb(*m_pGfxInfo,selected); //update to draw Bulb

}
void Bulb::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Bulb");
	CircuitFile << "BLB" << "\t" << ID << "\t" << getLabel() << "\t" << resistance<< "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Bulb::Operate()
{

}
void Bulb::Load2(int Value, string Label) {
	resistance=Value;
	setlabel(Label);
}
void  Bulb::savecommponnent(fstream& file) {

	file << "Bulb \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}

Bulb* Bulb::copy()
{
	Bulb* PPr = new Bulb(m_pGfxInfo, m_Label);

	return PPr;
}
ALLCOMPS Bulb::whichComponent() {
	return BULB;
}