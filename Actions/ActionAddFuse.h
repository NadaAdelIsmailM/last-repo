#ifndef ActionAddFuze_H
#define ActionAddFuze_H
#include "Action.h"
#include "..\Components\Fuse.h"


//Class responsible for adding a new resistor action
class ActionAddFuse : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	string maxcurrent;
public:
	ActionAddFuse(ApplicationManager* pApp);
	virtual ~ActionAddFuse(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionAddFuse::Undo();

	virtual void ActionAddFuse::Redo();
};
#endif
