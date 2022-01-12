#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "Connection.h"


//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:

protected:
	string m_Label;

	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2
	//static int ID;
	double resistance;
	double sourceVoltage; // internal resistance and voltage jump introduced by source
	bool selected;
	bool CompStatus;
	//Each terminal is connected to set of connections
	Connection *term1_connections[MAX_CONNS]; //list of pointers to connections
	Connection *term2_connections[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;


	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
	int static cid;
	int id;



public:

	//GraphicsInfo* m_pGfxInfo;
	Component(GraphicsInfo *r_GfxInfo);
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2
	virtual void Operate() = 0;	//Calculates the output voltage according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	bool IsInRegion(int m_x, int m_y)const;
	int getCompCenterX(UI*); // get horizontal/vertical centers of the component
	int getCompCenterY(UI*);
	int getGraphicsInfoY();
	int getGraphicsInfoX();
	GraphicsInfo* getGraphics();
	void addTerm1Conn(Connection*);
	void addTerm2Conn(Connection*);
	static void resetID();
	bool isSelected();
	void Select();
	void unSelect();
	int getTermcount(TerminalNum Term);
	Connection** getTermConn(TerminalNum Term);
	void setState(int S);
	int getResistance();
	void setSourceVoltage(int V);
	int getSourceVoltage();
	//void setState(int S);
	bool getCompState();
	void setTermi1Volt(double v);		//sets the voltage at terminal1
	void setTermi2Volt(double v);		//sets the voltage at terminal2
	void setlabel(string s);
	string getlabel() const;
	int gitid();
	//virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	//virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	//virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual void savecommponnent(fstream& file)=0;
	virtual void Load(string label,int value)=0;
	TerminalNum WhatTerminal(Connection* Conn); // returns the terminal to which a connection is connected
	virtual Component* copy() = 0;
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
