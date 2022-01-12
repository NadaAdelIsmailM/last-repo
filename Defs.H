#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application
//Terminals

enum TerminalNum { Term1, Term2 };
enum Status { ON, OFF };
//All possible actions
enum ActionType 
{
	ADD_RESISTOR,		//Add a resistor
	ADD_LAMP,//Add LAMP
	ADD_BATTERY,
	ADD_SWITCH,			//Add Switch
	ADD_GRND,
	ADD_BUZZER,
	ADD_FUSE,		
	ADD_CONNECTION,		//Add Wire Connection
	SWITCH_IMG,
	COPY,
	PASTE,
	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file
	editlabel,
	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DESIGGN,

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	SIMM,
	DESIGNN,
	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

enum ImageType {
	SIM,
	Actual,
};
enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum COMPSS
{
	RESISTOR,
	BULB,
	BUZZER,
	FUZE,
	SWITCH,
	BATTERY,
	GROUND,
	MODULE_1,
};
//Maximum number of connections that can be connected to any output components
#define MAX_CONNS 200





#endif