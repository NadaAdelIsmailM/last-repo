#include "Ground.h"
#include <iostream>
#include <string>
#include <fstream>
Ground::Ground(GraphicsInfo* r_GfxInfo)
{
}
Ground::Ground(GraphicsInfo* r_GfxInfo,string gname) :Component(r_GfxInfo)
{
	m_Label = gname;
}
//void Ground::ToSim() {}
void Ground::Draw(UI* pUI)
{
	pUI->DrawGround(*m_pGfxInfo,m_Label);

}

void Ground::Operate()
{

}



void  Ground::savecommponnent(fstream& file) {

	file << "Ground \t" << to_string(id) << "\t" << m_Label << "\t" << to_string(m_pGfxInfo->PointsList[0].x) << "\t" << to_string(m_pGfxInfo->PointsList[0].y);
}
void Ground::Load(string label, int value) {
	setlabel(label);
	resistance = value;



}