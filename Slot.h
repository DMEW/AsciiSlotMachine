#pragma once
#include <string>
#include "SlotWheel.h"
#include <Windows.h>

using namespace std;

class Slot
{
private:
	vector<string> _labels;
	string _payoutMsg;
	SlotWheel *_a, *_b, *_c;
	int _color;
	void SetWheels(int);
	void RandomMsg();

public:
	void JackPot();
	Slot(int color);
	~Slot();
	void PayOut();
	void Pull();
	void PrintSlot();

};

