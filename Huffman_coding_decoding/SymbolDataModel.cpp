#include "SymbolDataModel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

TreeInput SymbolDataModel::FileRead(string fileName)
{
	int numrows, numcols, maxval;
	vector<int> symbols;

	ifstream file(fileName, ios::binary);
	int charFile;
	if (!file.is_open()) { cout << "Error: file " << fileName << " is not opened\n"; exit(-1); }
	stringstream ss;
	string inputLine = ""; // First line : version    
	getline(file, inputLine);
	if (inputLine.compare("P5") != 0) cerr << "Version error" << endl;
	else cout << "Version : " << inputLine << endl; // Second line : comment
	getline(file, inputLine);
	cout << "Comment : " << inputLine << endl; // Third line : size
	file >> numcols >> numrows;
	cout << numcols << " columns and " << numrows << " rows" << endl; // reading maximum value
	file >> maxval;
	cout << "Max value " << maxval << endl;

	unsigned int numpixels = numrows * numcols;
	vector<uint8_t> data(numpixels);
	file.read(reinterpret_cast<char*>(data.data()), numpixels);
	vector<int> pixels(numpixels);
	std::copy(data.begin(), data.end(), pixels.begin());
	return TreeInput(pixels);
}

BlockModel SymbolDataModel::BlockModel2(vector<int> array, vector<int> frequency)
{
	vector<std::string> BlockModel2Array;
	vector<int> BlockModel2Frequency;
	int whileStep = 0;
	while (whileStep < size(array))
	{		
		int firstSymbol = array[whileStep];
		for (int i = 0; i < size(array); i++)
		{
			int secondSymbol = array[i];
			std::string symbolString;
			if (firstSymbol == 0)
			{
				symbolString = "0" + std::to_string(secondSymbol);
			}
			else
			{
				symbolString = std::to_string(firstSymbol) + std::to_string(secondSymbol);
			}
			int symbolFrequency = frequency[whileStep] * frequency[i];
			BlockModel2Array.push_back(symbolString);
			BlockModel2Frequency.push_back(symbolFrequency);
		}
		whileStep++;
	}
	BlockModel blockModel;
	blockModel.BlockModel2Array = BlockModel2Array;
	blockModel.BlockModel2Frequency = BlockModel2Frequency;
	return blockModel;
}
