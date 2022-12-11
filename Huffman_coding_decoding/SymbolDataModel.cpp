#include "SymbolDataModel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

TreeInput SymbolDataModel::FileRead(string fileName)
{
	int row = 0, col = 0, numrows = 0, numcols = 0;
	ifstream myfile;
	char charFile;
	vector<char> symbols;
	/*char fileOpen;*/

	myfile.open(fileName);
	if(!myfile.is_open()) { cout << "Error: file " << fileName << " is not opened\n"; exit(-1); }
	/*while (myfile)
	{
		fileOpen = myfile.get();
		treeInput.symbols.push_back(fileOpen);
		std::cout << fileOpen;			
	}*/

	stringstream ss;
	string inputLine = "";

	// First line : version	
	getline(myfile, inputLine);
	if (inputLine.compare("P5") != 0) cerr << "Version error" << endl;
	else cout << "Version : " << inputLine << endl;

	// Second line : comment
	getline(myfile, inputLine);
	cout << "Comment : " << inputLine << endl;

	// Continue with a stringstream
	ss << myfile.rdbuf();
	// Third line : size
	ss >> numcols >> numrows;
	cout << numcols << " columns and " << numrows << " rows" << endl;

	for (row = 0; row < numrows; ++row)
		for (col = 0; col < numcols; ++col)
		{
			ss >> charFile;
			symbols.push_back(charFile);
		}
    
	TreeInput treeInput = TreeInput(symbols);

	return treeInput;
}