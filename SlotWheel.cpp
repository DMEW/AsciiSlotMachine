#include "stdafx.h"
#include "SlotWheel.h"
#include <iostream>
#include <time.h>

SlotWheel::SlotWheel()
{
	SetWheel("***");
}
void SlotWheel::SpinWheel()
{
	int odds = rand() % 100;
	try{

		if (odds == 1)
			SetWheel("$$$");
		else if (odds > 1 && odds < 20)
			SetWheel(" ~ ");
		else if (odds >= 20 && odds < 40)
			SetWheel(" 7 ");
		else if (odds >= 40 && odds < 70)
			SetWheel(" # ");
		else if (odds >= 70 && odds <= 80)
			SetWheel(" @ ");
		else if (odds >= 80 && odds < 100)
			SetWheel("***");
	}
	catch(exception e)
	{
		if (e.what() == "InvalidLabel")
		{
			cout << "Unexpected Error: Invalid Slot Wheel Set...Exiting" << endl;
			exit(0);
		}
	}
}
void SlotWheel::SetWheel(string label)
{
	if (label == " ~ ")
	{
		_label = label;
		_color = 0xB0;
	}
	else if (label == "$$$")
	{
		_label = label;
		_color = 0x0A;
	}
	else if (label == " 7 ")
	{
		_label = label;
		_color = 0x0C;
	}
	else if (label == " # ")
	{
		_label = label;
		_color = 0xF5;

	}
	else if (label == " @ ")
	{
		_label = label;
		_color = 0xC1;
	}
	else if (label == "***")
	{
		_label = label;
		_color = 0xDE;
	}
	else
	{
		throw exception("InvalidLabel");
		return;
	}
}

string SlotWheel::GetLabel()
{
	return _label;
}

int SlotWheel::GetColor()
{
	return _color;
}

SlotWheel::~SlotWheel()
{
}
