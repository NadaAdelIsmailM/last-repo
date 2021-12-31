#include "elabel.h"

#include <string>

elabel::elabel(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	
}


void elabel::Operate()
{

}

void elabel::savecommponnent(fstream& file)
{
}

void elabel:: set_label(string a) {
	m_Label = a;
}



void elabel::Draw(UI*){
}

void elabel::Load(string label, int value)
{
}
