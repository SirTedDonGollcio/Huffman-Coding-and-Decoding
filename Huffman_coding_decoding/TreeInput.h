#pragma once
using namespace std;
#include <vector>
#include <map>

class TreeInput
{
private:
	map<int, int> symbolsFrequencies;
public:
	TreeInput(vector<int> symbols);
	TreeInput() {};
	vector<int>	extractUniqueSymbols();
	vector<int> extractFrequencies();
};

