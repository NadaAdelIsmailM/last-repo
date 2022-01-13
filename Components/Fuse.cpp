#include "Fuse.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Fuse::Fuse(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Fuse::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawFuse(*m_pGfxInfo, selected);




}
void Fuse::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Fuse");
	CircuitFile << "FUs" << "\t" << ID << "\t" << getLabel() << "\t" << getResistance() << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Fuse::Operate()
{

}
void Fuse::Load2(int Value, string Label) {
	resistance = Value;
	setlabel(Label);
}
ALLCOMPS Fuse::whichComponent() {
	return 	FUSE;
}