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
	string inputLine = "";

	// First line : version	
	getline(file, inputLine);
	if (inputLine.compare("P5") != 0) cerr << "Version error" << endl;
	else cout << "Version : " << inputLine << endl;

	// Second line : comment
	getline(file, inputLine);
	cout << "Comment : " << inputLine << endl;

	// Third line : size
	file >> numcols >> numrows;
	cout << numcols << " columns and " << numrows << " rows" << endl;

	// reading maximum value
	file >> maxval;
	cout << "Max value " << maxval << endl;

	unsigned int numpixels = numrows * numcols;

	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<char> buffer(numpixels);
	file.read(buffer.data(), numpixels);
	for (int i = 0; i < numpixels; i++) {
		symbols.push_back(buffer[i] + 128); // shift 128 to the right when saving since we are reading signed chars (-128 to 127)
	}

	return TreeInput(symbols);
}

BlockModel SymbolDataModel::BlockModel2(vector<int> array, vector<int> frequency)
{
	vector<std::string> BlockModel2Array;
	vector<int> BlockModel2Frequency;
	int whileStep = 0;
	while (whileStep < size(array))
	{		
		char firstSymbol = array[whileStep];
		for (int i = 0; i < size(array); i++)
		{
			char secondSymbol = array[i];
			std::string symbolString;
			if (firstSymbol == 0)
			{
				symbolString = "0" + std::string(1, secondSymbol);
			}
			else
			{
				symbolString = std::string(1, firstSymbol) + std::string(1, secondSymbol);
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

