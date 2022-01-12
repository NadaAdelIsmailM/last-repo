#pragma once
#include "../UI/UI.h"

class Component;	//forward class declaration

class Connection
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection
	bool selected;
public:
	void setselect(bool);
	bool IsSelected() const;
	Connection(GraphicsInfo *r_GfxInfo, Component *cmp1=nullptr, Component *cmp2=nullptr);
	void Draw(UI* );	
	Component* getcmp1() const;
	Component* getcmp2() const;

};
