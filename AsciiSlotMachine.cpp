// AsciiSlotMachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include "Slot.h"
#include <stdlib.h>
#include <time.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void PrintBanner()
{
	
	SetConsoleTitle(L"Ascii Casino");
	SetConsoleTextAttribute(hConsole, 0xE);
	string banner = "          _   _   _   _   _     _   _   _   _   _   _  "
					"\n\t / \\ / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ / \\ "
					 "\n\t( A | S | C | I | I ) ( C | A | S | I | N | O )"
					  "\n\t \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ ";
	cout << banner << endl << endl << endl << "\tGet 3";
	SetConsoleTextAttribute(hConsole, 0x0A);
	cout << " $$$ "; 
	SetConsoleTextAttribute(hConsole, 0xE);
	cout << "signs and win the $15 Amazon Gift code" << endl;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	PrintBanner();
	srand(time(NULL));
	//Keeps random color range between 0x09 and 0x0f
	int rndmColor = (rand() % 0x07) + 0x09;
	Slot *s = new Slot(rndmColor);
	s->PrintSlot();
	while (1)
	{
		cout << endl << endl << "\t\tPress Space to Spin...";
		do
		{

		} while (!(GetKeyState(VK_SPACE) & 0x8000));
		s->Pull();
		system("cls");
		PrintBanner();
		s->PrintSlot();
	}
	return 0;

}