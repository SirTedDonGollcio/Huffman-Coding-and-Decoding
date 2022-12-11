#pragma once
using namespace std;
#include <vector>

class TreeInput
{
public:
	vector<char> symbols;
	vector<int> frequencyOfSigns;
	TreeInput(vector<char> symbols);
	TreeInput() {};
};

