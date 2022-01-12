#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;

}

bool Component::IsInRegion(int m_x, int m_y) const {
		if ((m_pGfxInfo->PointsList[0].x < m_x) && (m_x < m_pGfxInfo->PointsList[1].x) && (m_pGfxInfo->PointsList[0].y < m_y) && (m_y < m_pGfxInfo->PointsList[1].y))
			return true;
		else
			return false;

}
bool Component::IsSelected() const {
	return this->selected;
}
void Component::setselect(bool x) {
	this->selected = x;
}

Component::~Component()
{

}

