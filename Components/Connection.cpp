#include "Connection.h"
#include "Component.h"
#include <iostream>
#include <string>
#include <fstream>
Connection::Connection(GraphicsInfo *r_GfxInfo,string f, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	c_label;
}
Connection::Connection(GraphicsInfo* r_GfxInfo)
{
	pGfxInfo = r_GfxInfo;

}

void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, c_label, selected);
}
GraphicsInfo* Connection::getGraphics() const{
	return pGfxInfo;
}

int Connection::WhatComp(Component* comp) {
	if (Cmpnt1 == comp)
		return 1;
	else if (Cmpnt1 == comp)
		return 2;
	else
		return 0;
}
bool Connection::isSelected() {

	return selected;
}
void Connection::Select() {
	if (selected == false)
		selected = true;
	else
		selected = false;
}
void Connection::unSelect() {
	selected = false;
}

double Connection::SlopeofLine() {
	double x1 = pGfxInfo->PointsList[0].x;
	double x2 = pGfxInfo->PointsList[1].x;
	double y1 = pGfxInfo->PointsList[0].y;
	double y2 = pGfxInfo->PointsList[1].y;

	return ((y2 - y1) / (x2 - x1));
}
void Connection::Load(Component* comp1, Component* comp2) {
	Cmpnt1 = comp1;
	Cmpnt2 = comp2;
	GraphicsInfo* G1, * G2;
	G1 = Cmpnt1->getGraphics();
	G2 = Cmpnt2->getGraphics();
	if (pGfxInfo->PointsList[0].x < G1->PointsList[0].x)
		Cmpnt1->addTerm1Conn(this);
	else 
		Cmpnt1->addTerm2Conn(this);
	if (pGfxInfo->PointsList[1].x < G1->PointsList[1].x)
		Cmpnt2->addTerm1Conn(this);
	else
		Cmpnt1->addTerm2Conn(this);
}
void Connection::saveconnection(fstream& file) {
	int x = Cmpnt1->gitid();
	int y = Cmpnt2->gitid();

	file << x << " connected " << y << endl;
}
