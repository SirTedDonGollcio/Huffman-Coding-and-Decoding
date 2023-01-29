#include "TreeInput.h"
#include <map>
#include <iostream>
using namespace std;

TreeInput::TreeInput(vector<int> symbols)
{
	for (int i = 0; i < symbols.size(); i++) {
		symbolsFrequencies[symbols[i]]++;
		input.push_back(symbols[i]);
	}
}

vector<int> TreeInput::extractUniqueSymbols() {
	vector<int> symbols;
	for (auto it = this->symbolsFrequencies.begin(); it != this->symbolsFrequencies.end(); it++) {
		symbols.push_back(it->first);
	}
	return symbols;
}

vector<int> TreeInput::extractFrequencies() {
	vector<int> frequencies;
	for (auto it = this->symbolsFrequencies.begin(); it != this->symbolsFrequencies.end(); it++) {
		frequencies.push_back(it->second);
	}
	return frequencies;
}