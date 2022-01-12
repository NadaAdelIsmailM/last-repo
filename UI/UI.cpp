#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	img = SIM;


	//Initilaize interface colors
	DrawColor = VIOLET;
	SelectColor = BLUE;
	ConnColor = CYAN;
	MsgColor = WHITE;
	BkGrndColor =VIOLET;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Circuit Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
	
}

int UI::getToolBarHeight() {
	return ToolBarHeight;
}
int UI::Height() {
	return height;
}
int UI::getWidth() {
	return width;
}
int UI::getStatusBarHeight() {
	return StatusBarHeight;
}
int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

void UI::GetLastPointClicked(int& x, int& y)
{
	pWind->GetMouseCoord(x, y);
}

string UI::GetString(string msg, string value)
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar

	UI::PrintMsg(msg);
	string userInput;
	char Key;
	userInput = value;
	while (1)
	{
		pWind->WaitKeyPress(Key);

		switch (Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input

		case 13:		//ENTER key is pressed
			return userInput;

		case 8:		//BackSpace is pressed
			if (userInput.size() > 0)
				userInput.resize(userInput.size() - 1);
			break;

		default:
			userInput += Key;
		};

		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_BULB:	return ADD_LAMP;
			case ITM_BATTERY:	return ADD_BATTERY;
			case ITM_SWITCH:	return ADD_SWITCH;
			case ITM_GRND:	return ADD_GRND;
			case ITM_BUZZ:	return ADD_BUZZER;
			case ITM_FUSE:	return ADD_FUSE;
			case ITM_CONNEC:	return ADD_CONNECTION;
			case ITM_LOAD:       return LOAD;
			case ITM_editlabel:	return editlabel;
			case ITM_SIM: return SIM_MODE;
			case ITM_SAVE:	return SAVE;
			case ITM_EXIT:	return EXIT;
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < ToolBarHeight)
		{
			int ClickedItemOrder = (x / ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_EXITTWO: return EXIT;
			case ITM_DESIGN: return DESIGNN;
			case ITM_CIRC_SIM: return SIMM;
			}
		}

	}
}


//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{	
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(30, BOLD | ITALICIZED, BY_NAME, "Gunplay"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(VIOLET, 1);
	pWind->SetBrush(VIOLET);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}

void UI::SwitchImageType() {
	if (img == Actual)
		img = SIM;
	else
		img = Actual;
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "Images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_BUZZ] = "Images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_BULB] = "Images\\Menu\\Menu_Bulb.jpg";
	MenuItemImages[ITM_CONNEC] = "Images\\Menu\\Menu_Wire.jpg";
	MenuItemImages[ITM_BATTERY] = "Images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_SWITCH] = "Images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_GRND] = "Images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_FUSE] = "Images\\Menu\\Menu_Fuse.jpg";
	MenuItemImages[ITM_LOAD] = "Images\\Menu\\Load.jpg";
	MenuItemImages[ITM_SIM] = "Images\\Menu\\Menu_Simm.jpg";
	MenuItemImages[ITM_SAVE] = "Images\\Menu\\Menu_save.jpg";
	MenuItemImages[ITM_editlabel] = "Images\\Menu\\Menu_editlabel.jpg";
		//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string SimulationMenuImages[ITM_SIM_CNT];
	SimulationMenuImages[ITM_CIRC_SIM] = "images\\Sim Menu\\Menu_Simulate.jpg";
	SimulationMenuImages[ITM_DESIGN] = "images\\Sim Menu\\Menu_Design.jpg";
	SimulationMenuImages[ITM_EXITTWO] = "images\\Sim Menu\\Menu_Exit.jpg";

	for (int i = 0; i < ITM_SIM_CNT; i++)
	{
		pWind->DrawImage(SimulationMenuImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
	}
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);



}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo& r_GfxInfo, string b, bool selected) const
{
	string ResImage;
	if (selected)
		ResImage = "Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	pWind->SetPen(BLUE);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + (COMP_WIDTH / 4) - 30, (r_GfxInfo.PointsList[0].y), b);
}


void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, string b, bool selected) const
{
	string BuzzImage;
	if (selected)
		BuzzImage = "Images\\Comp\\Buzzer_HI.jpg";
	else
		BuzzImage = "Images\\Comp\\Buzzer.jpg";


	pWind->DrawImage(BuzzImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	pWind->SetPen(BLUE);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + (COMP_WIDTH / 4) - 30, (r_GfxInfo.PointsList[0].y), b);

}
//TODO: Add similar functions to draw all other components
void UI::DrawBulb(const GraphicsInfo& r_GfxInfo, string b, bool selected, bool IsOn) const
{
	string BuzzImage;
	if (selected && IsOn)
		BuzzImage = "Images\\Comp\\Bulb_ON_HI.jpg";
	else if (selected && (!IsOn))
		BuzzImage = "Images\\Comp\\Bulb_OFF_HI.jpg";
	else if ((!selected) && IsOn)
		BuzzImage = "Images\\Comp\\Bulb_ON.jpg";
	else if ((!selected) && (!IsOn))
		BuzzImage = "Images\\Comp\\Bulb_OFF.jpg";


	pWind->DrawImage(BuzzImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	pWind->SetPen(BLUE);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + (COMP_WIDTH / 4) - 30, (r_GfxInfo.PointsList[0].y), b);
}



void UI::DrawConnection(const GraphicsInfo& r_GfxInfo, string b, bool selected) const
{
	if (selected)
		pWind->SetPen(RED, 6);
	else
		pWind->SetPen(BLACK, 6);

	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y, FRAME);
	pWind->SetPen(BROWN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + 30, (r_GfxInfo.PointsList[0].y), b);
}

void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, string bname, bool selected) const
{
	string BattImage;
	if (selected)
		BattImage = "Images\\Comp\\Battery_HI.jpg";	//use image of highlighted Battery
	else
		BattImage = "Images\\Comp\\Battery.jpg";	//use image of the normal battery

	//Draw battery at Gfx_Info (1st corner)
	pWind->DrawImage(BattImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	pWind->SetPen(BLUE);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + (COMP_WIDTH / 4) - 30, (r_GfxInfo.PointsList[0].y), bname);
}



//the function which draws the ground
void UI::DrawGround(const GraphicsInfo& r_GfxInfo, string g, bool selected) const
{
	string GroundImage;
	if (selected)
		GroundImage = "Images\\Comp\\Ground_HI.jpg";	//use image of highlighted ground
	else
		GroundImage = "Images\\Comp\\Ground.jpg";	//use image of the normal ground

	//Draw ground at Gfx_Info (1st corner)
	pWind->DrawImage(GroundImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	pWind->SetPen(BLUE);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + (COMP_WIDTH / 4) - 30, (r_GfxInfo.PointsList[0].y), g);
}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, string b, bool selected) const
{
	string SwitchImage;
	if (selected)
		SwitchImage = "Images\\comp\\Switchclosed_HI.jpg";	//use image of closed switch
	else
		SwitchImage = "Images\\comp\\switchopen.jpg";	//use image of the open switch

	pWind->DrawImage(SwitchImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	pWind->SetPen(BLUE);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + (COMP_WIDTH / 4) - 30, (r_GfxInfo.PointsList[0].y), b);
}


void UI::DrawFuse(const GraphicsInfo& r_GfxInfo, string f, bool selected) const
{
	string FuseImage;
	if (selected)
		FuseImage = "Images\\comp\\fuse_HI.jpg";	//use image of highlighted fuse
	else
		FuseImage = "Images\\comp\\fuse.jpg";	//use image of the normal fuse

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(FuseImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	pWind->SetPen(BLUE);
	pWind->DrawString(r_GfxInfo.PointsList[0].x + (COMP_WIDTH / 4) - 30, (r_GfxInfo.PointsList[0].y), f);
}



UI::~UI()
{
	delete pWind;
}
