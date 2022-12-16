#include "TreeInput.h"
#include <map>
using namespace std;

TreeInput::TreeInput(vector<int> symbols)
{
	for (int i = 0; i < symbols.size(); i++) {
		if (this->symbolsFrequencies.find(symbols[i]) == this->symbolsFrequencies.end()) {
			this->symbolsFrequencies[symbols[i]] = 1;
		}
		else {
			this->symbolsFrequencies[symbols[i]]++;
		}
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