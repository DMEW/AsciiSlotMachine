#include "stdafx.h"
#include "Slot.h"
#include <iostream>

#define WIN32_LEAN_AND_MEAN

using namespace std;

Slot::Slot(int color)
{
	_color = color;

	_a = new SlotWheel();
	_b = new SlotWheel();
	_c = new SlotWheel();
}

void Slot::PayOut()
{
	if (_a->GetLabel() == "$$$" && _b->GetLabel() == "$$$" && _c->GetLabel() == "$$$")
		JackPot();
	else
		RandomMsg();
}
void Slot::JackPot()
{
	vector<int> d = { 0xbd, 0xb5, 0xd4, 0xa1, 0xca, 0xa2, 0xdf, 0xbd, 0xdf, 0xb4, 0xd0, 0xca, 0xb1, 0xad, 0xb2, 0xd4 };
	_payoutMsg = "\tYOU WON!!!!!  \n\n\t Here is the $15 Amazon Gift Code:";
	for(int i=0;i<d.size();i++)
		_payoutMsg += (char)(d[i] ^ 231);
}
void Slot::RandomMsg()
{
	if ((_a->GetLabel() == _b->GetLabel()) && (_a->GetLabel() == _c->GetLabel()))
	{
		_payoutMsg = "Nice match! but no win...";
	}
	else
	{
		int rndm = rand() % 6;

		switch (rndm)
		{
		case 0:
			_payoutMsg = "Sorry...no win";
			break;
		case 1:
			_payoutMsg = "This should help: https://tuts4you.com/download.php?view.3554";
			break;
		case 2:
			_payoutMsg = "No Win...FYI, The payout code is encrypted, so just dumping \"strings\" wont work";
			break;
		case 3:
			_payoutMsg = "Good thing this isnt real money";
			break;
		case 4:
			_payoutMsg = "Vote on the South Sound Hackers topic poll!";
			break;
		case 5:
			_payoutMsg = "Nope...If you're have a question or having trouble, post on the Meetup Message Boards";
			break;
		}
	}
}
void Slot::Pull()
{
	_a->SpinWheel();
	_b->SpinWheel();
	_c->SpinWheel();
	Sleep(300);

	PayOut();
}

void Slot::PrintSlot()
{
	//check null slotwheels

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, _color);
	cout  << "\t             .-------."
		"\n\t             |       |"
		"\n\t ____________|_______|____________"
		"\n\t |  __    __    ___  _____   __    |"
		"\n\t | / _\\  / /   /___\\/__   \\ / _\\   |"
		"\n\t | \\ \\  / /   //  //  / /\\ \\\\ \\  25|"
		"\n\t | _\\ \\/ /___/ \\_//  / /  \\/_\\ \\ []|"
		"\n\t | \\__/\\____/\\___/   \\/     \\__/ []|(__)"
		"\n\t |===_______===_______===_______===| ||"
		"\n\t ||^| _____ |*| _____ |*| _____ |*|| ||"
		"\n\t ||*||     ||*||     ||*||     ||*|| ||"
		"\n\t ||*|| ";
		SetConsoleTextAttribute(hConsole, _a->GetColor());
		cout << _a->GetLabel().c_str();
		SetConsoleTextAttribute(hConsole, _color);
		cout << " ||*|| ";
		SetConsoleTextAttribute(hConsole, _b->GetColor());
		cout << _b->GetLabel().c_str();
		SetConsoleTextAttribute(hConsole, _color); 
		cout << " ||*|| ";
		SetConsoleTextAttribute(hConsole, _c->GetColor());
		cout << _c->GetLabel().c_str();
		SetConsoleTextAttribute(hConsole, _color);
		cout <<	" ||*|| ||"
		"\n\t ||*||_____||*||_____||*||_____||*|| ||"
		"\n\t ||*|_______|*|_______|*|_______|%||_//"
		"\n\t |===       ===       ===       ===|_/"
		"\n\t |  =___________________________===|"
		"\n\t |  /___________________________\\  |"
		"\n\t |   |                         |   |"
		"\n\t _|    \\_______________________/    |_"
		"\n\t(_____________________________________)";

		if (!_payoutMsg.empty())
		{
			SetConsoleTextAttribute(hConsole, 0xE);
			cout << endl << endl << _payoutMsg;
		}
}
Slot::~Slot()
{
}
