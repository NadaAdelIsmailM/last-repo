#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
	selected = false;
	CompStatus = 0;
	id = cid++;
}
Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
	CompStatus = 0;
}
void Component::setlabel(string s) {
	m_Label = s;
}
string Component::getlabel()const {
	return m_Label;
}
void Component::addTerm1Conn(Connection* c) {
	term1_connections[term1_conn_count++] = c;
}
void Component::addTerm2Conn(Connection* c) {
	term2_connections[term2_conn_count++] = c;
}
int Component::getTermcount(TerminalNum Term) {
	switch (Term) {
	case Term1:
		return term1_conn_count;
		break;
	case Term2:
		return term2_conn_count;
		break;
	default: return 0;
	}
}

Connection** Component::getTermConn(TerminalNum Term) {
	switch (Term) {
	case Term1:
		return term1_connections;
		break;
	case Term2:
		return term2_connections;
		break;
	default:
		return nullptr;
	}

}

//void Component::resetID() {
	//ID = 1;
//}
bool Component::IsInRegion(int m_x, int m_y) const {
		if ((m_pGfxInfo->PointsList[0].x < m_x) && (m_x < m_pGfxInfo->PointsList[1].x) && (m_pGfxInfo->PointsList[0].y < m_y) && (m_y < m_pGfxInfo->PointsList[1].y))
			return true;
		else
			return false;

}

//void Component::savecommponnent(fstream& file)
//{
//}



//void Component::Load(string label, int value) {}


bool Component::isSelected() {

	return selected;
}

void Component::Select() {
		selected = true;
}

void Component::unSelect() {
	selected = false;
}

int Component::getResistance() {
	return resistance;
}

void Component::setState(int S) {
	switch (S) {
	case 1:
		CompStatus = false;
		break;
	case 0:
		CompStatus = true;
		break;
	default:
		CompStatus = false;
	}
}

bool Component::getCompState() {
	return CompStatus;
}
void Component::setSourceVoltage(int V) {
	sourceVoltage = V;
}
int Component::getSourceVoltage() {
	return sourceVoltage;
}

int Component::getCompCenterX(UI* pUI) {
	return m_pGfxInfo->PointsList[0].x + pUI->getCompWidth() / 2;
}

int Component::getCompCenterY(UI* pUI) {
	return m_pGfxInfo->PointsList[0].y + pUI->getCompHeight() / 2;
}

GraphicsInfo* Component::getGraphics() {
	return m_pGfxInfo;
}

int Component::getGraphicsInfoY() {
	return m_pGfxInfo->PointsList[0].x;
}

int Component::getGraphicsInfoX() {
	return m_pGfxInfo->PointsList[0].y;
}

int Component::cid = 1;
int Component::gitid() { return id; }


void Component::setTermi1Volt(double v) {
	term1_volt = v;
}//sets the voltage at terminal1
void Component::setTermi2Volt(double v) {
	term2_volt = v;
}	//sets the voltage at terminal2

TerminalNum Component::WhatTerminal(Connection* Conn) {
	for (int i = 0; i < term1_conn_count; i++) {
		if (term1_connections[i] == Conn)
			return Term1;
	}

	for (int i = 0; i < term2_conn_count; i++)
		if (term2_connections[i] == Conn) {
			return Term2;
		}
}

Component::~Component()
{

}
