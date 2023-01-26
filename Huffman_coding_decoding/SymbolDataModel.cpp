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

	if(!file.is_open()) { cout << "Error: file " << fileName << " is not opened\n"; exit(-1); }
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