#pragma once
using namespace std;
#include "TreeInput.h"
#include <string>
#include <list>

struct BlockModel
{
	vector<std::string> BlockModel2Array;
	vector<int> BlockModel2Frequency;
};

class SymbolDataModel
{
public:
	TreeInput FileRead(string fileName);
	BlockModel BlockModel2(vector<int> array, vector<int> frequency);
};
