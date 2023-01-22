#pragma once
using namespace std;
#include <vector>



class DataGenerator
{
public: 
	static vector<int> uniformGenerate(int length);
	static vector<int> normalGenerate(int length);
	static vector<int> laplaceGenerate(int length);
};

