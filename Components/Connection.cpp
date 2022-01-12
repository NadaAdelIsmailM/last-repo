#include "Connection.h"

Connection::Connection(GraphicsInfo *r_GfxInfo, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, selected);
}

bool Connection::IsSelected() const {
	return this->selected;
}
void Connection::setselect(bool x) {
	this->selected = x;
}
Component* Connection::getcmp1() const {
	return this->Cmpnt1;
}
Component* Connection::getcmp2() const {
	return this->Cmpnt2;
}