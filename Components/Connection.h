#pragma once
#include "../UI/UI.h"

class Component;	//forward class declaration

class Connection
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection
	string c_label;
	bool selected;
public:
	Connection::Connection(GraphicsInfo* r_GfxInfo);
	Connection(GraphicsInfo* r_GfxInfo, string d, Component* cmp1 = nullptr, Component* cmp2 = nullptr);
	virtual void Draw(UI* );
	double SlopeofLine();
	GraphicsInfo* getGraphics() const;
	Component* getComp(int n);
	void Load(Component* cmp1, Component* cmp2);
	bool isSelected();
	void Select();
	void unSelect();
	void saveconnection(fstream& file);
	//virtual void ToSim();
};
