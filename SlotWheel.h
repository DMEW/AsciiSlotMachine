#pragma once
#include <string>
#include <vector>
using namespace std;

class SlotWheel
{
friend class SlotLogic;
private:
	string _label;
	int _color;
	void SetWheel(string label);
public:
	SlotWheel();
	string GetLabel();
	void SpinWheel();
	int GetColor();
	~SlotWheel();
};

