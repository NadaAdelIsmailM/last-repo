#include "Action.h"



//Class responsible for adding a new resistor action
class ActionSwitchActual : public Action
{
private:
public:
	ActionSwitchActual(ApplicationManager* pApp);
	virtual ~ActionSwitchActual(void);
	//virtual void SimulationMode();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void ActionSwitchActual::Undo();

	virtual void ActionSwitchActual::Redo();
};

