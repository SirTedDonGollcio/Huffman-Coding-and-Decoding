#include "SymbolDataModel.h"
#include "DataGenerator.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
	using namespace std;

//#define MAX_TREE_HT 50


class Node {
public:
	char symbol;
	double frequency;
	Node* left_node;
	Node* right_node;
	Node() {
		char symbol = NULL;
		double frequency = 0;
		Node* left_node = NULL;
		Node* right_node = NULL;
	}
};

class Tree {
public:
	vector <Node> nodes;
	Node* top = new Node;
};

class Node_2 {
public:
	std::string symbol;
	double frequency;
	Node_2* left_node;
	Node_2* right_node;
	Node_2() {
		char symbol = NULL;
		double frequency = 0;
		Node_2* left_node = NULL;
		Node_2* right_node = NULL;
	}
};

class Tree_2 {
public:
	vector <Node_2> nodes;
	Node_2* top = new Node_2;
};

void printTree(Node * temp, vector <int> whichWayIveGone)
{
	if (temp->left_node != NULL)
	{
		whichWayIveGone.push_back(0);
		printTree(temp->left_node, whichWayIveGone);
		whichWayIveGone.pop_back();
	}
	if (temp->right_node != NULL)
	{
		whichWayIveGone.push_back(1);
		printTree(temp->right_node, whichWayIveGone);
	}
	if (temp->left_node == NULL && temp->right_node == NULL)
	{
		cout << "Im terminal leaf with symbol: " << (int)temp->symbol << " and frequancy: " << temp->frequency << " and i've been going through the: ";
		for (int i = 0; i < whichWayIveGone.size(); i++)
		{
			cout << whichWayIveGone[i];
		}
		cout << endl;
	}
}

void decode(Node* temp, vector <int> whichWayIveGone, char symb)
{
	if (temp->left_node != NULL)
	{
		whichWayIveGone.push_back(0);
		decode(temp->left_node, whichWayIveGone, symb);
		whichWayIveGone.pop_back();
	}
	if (temp->right_node != NULL)
	{
		whichWayIveGone.push_back(1);
		decode(temp->right_node, whichWayIveGone, symb);
	}
	if (temp->left_node == NULL && temp->right_node == NULL)
	{
		if (temp->symbol == symb)
		{
			cout << "Im decoding: " << (int)temp->symbol << " to: ";
			for (int i = 0; i < whichWayIveGone.size(); i++)
			{
				cout << whichWayIveGone[i];
			}
			cout << endl;
		}
		
	}
}

void decode_s(Node* temp, vector <int> whichWayIveGone, char symb, vector<string> &path)
{
	if (temp->left_node != NULL)
	{
		whichWayIveGone.push_back(48);
		decode_s(temp->left_node, whichWayIveGone, symb, path);
		whichWayIveGone.pop_back();
	}
	if (temp->right_node != NULL)
	{
		whichWayIveGone.push_back(49);
		decode_s(temp->right_node, whichWayIveGone, symb, path);
	}
	if (temp->left_node == NULL && temp->right_node == NULL)
	{
		if (temp->symbol == symb)
		{
			string tmp;
			for (int i = 0; i < whichWayIveGone.size(); i++)
			{
				tmp.push_back((char)whichWayIveGone[i]);
			}
			path.push_back(tmp);
		}
	}
}


void printTree_2(Node_2* temp, vector <int> whichWayIveGone)
{
	if (temp->left_node != NULL)
	{
		whichWayIveGone.push_back(0);
		printTree_2(temp->left_node, whichWayIveGone);
		whichWayIveGone.pop_back();
	}
	if (temp->right_node != NULL)
	{
		whichWayIveGone.push_back(1);
		printTree_2(temp->right_node, whichWayIveGone);
	}
	if (temp->left_node == NULL && temp->right_node == NULL && temp->symbol.size() == 2)
	{
		int firstchar = temp->symbol[0];
	    int secondchar = temp->symbol[1];
		cout << "Im terminal leaf with symbol: " << firstchar << secondchar << " and frequancy: " << temp->frequency << " and i've been going through the: ";
		
		for (int i = 0; i < whichWayIveGone.size(); i++)
		{
			cout << whichWayIveGone[i];
		}
		cout << endl;
	}
}

void decode_2(Node_2* temp, vector <int> whichWayIveGone, std::string symb)
{
	if (temp->left_node != NULL)
	{
		whichWayIveGone.push_back(0);
		decode_2(temp->left_node, whichWayIveGone, symb);
		whichWayIveGone.pop_back();
	}
	if (temp->right_node != NULL)
	{
		whichWayIveGone.push_back(1);
		decode_2(temp->right_node, whichWayIveGone, symb);
	}
	if (temp->left_node == NULL && temp->right_node == NULL && temp->symbol.size() == 2)
	{
		if (temp->symbol == symb)
		{
			int firstchar = temp->symbol[0];
			int secondchar = temp->symbol[1];
			cout << "Im decoding: " << firstchar << secondchar << " to: ";
			for (int i = 0; i < whichWayIveGone.size(); i++)
			{
				cout << whichWayIveGone[i];
			}
			cout << endl;
		}

	}
}

void decode_2s(Node_2* temp, vector <int> whichWayIveGone, std::string symb)
{
	if (temp->left_node != NULL)
	{
		whichWayIveGone.push_back(48);
		decode_2s(temp->left_node, whichWayIveGone, symb);
		whichWayIveGone.pop_back();
	}
	if (temp->right_node != NULL)
	{
		whichWayIveGone.push_back(49);
		decode_2s(temp->right_node, whichWayIveGone, symb);
	}
	if (temp->left_node == NULL && temp->right_node == NULL && temp->symbol.size() == 2)
	{
		if (temp->symbol == symb)
		{
			//cout << "Im decoding: " << (int)temp->symbol << " to: ";
			std::ofstream myfile;
			myfile.open("coded_withColons.txt", ios::app);
			std::ofstream myfile2;
			myfile2.open("coded.txt", ios::app);
			for (int i = 0; i < whichWayIveGone.size(); i++)
			{
				//cout << (char)whichWayIveGone[i];
				myfile << (char)whichWayIveGone[i];
				myfile2 << (char)whichWayIveGone[i];
			}
			myfile << ";";
			myfile.close();
			myfile2.close();

			//cout << s;
			//cout << endl;
		}

	}
}

float average_bit_length_output_code(vector<int> f, vector<string> output)
{
	long float sum = 0;
	for (int i = 0; i < f.size(); i++)
	{
		sum += f[i];
	}

	float prob;
	float avgBitLengthSum = 0;

	for (int i = 0; i < f.size(); i++)
	{
		prob = (float)f[i] / sum;
		avgBitLengthSum += prob * output[i].size();
	}
	return avgBitLengthSum;
}

void HuffmanCode_makeTree(vector<int> code_source, vector<int> frequency_of_signs, int size, vector<int> arrayofCode, TreeInput ti, string name)
{
	//struct MinHNode* root = buildHfTree(item, freq, size);

	//Node *left_node, *right_node, *top_node;
	Tree tree_inProcess;

	char tempC;
	int tempI;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (frequency_of_signs[i] < frequency_of_signs[i + 1])
			{
				tempC = code_source[i + 1];
				tempI = frequency_of_signs[i + 1];
				code_source[i + 1] = code_source[i];
				frequency_of_signs[i + 1] = frequency_of_signs[i];
				code_source[i] = tempC;
				frequency_of_signs[i] = tempI;
			}
		}
	}
	Node initial_node;
	tree_inProcess.nodes.push_back(initial_node);
	/*for (int i = 0; i < size; i++)
	{
		cout << frequency_of_signs[i] << code_source[i] << " ";
	}*/

	Node* address_ofTopNode = new Node;

	if (size == 1)
	{
		Node only_node;
		only_node.frequency = frequency_of_signs[0];
		only_node.symbol = code_source[0];

		tree_inProcess.nodes.push_back(only_node);

		initial_node.right_node = &only_node;
		initial_node.frequency = initial_node.right_node->frequency;

		tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[1];
		tree_inProcess.nodes[0].frequency = tree_inProcess.nodes[0].right_node->frequency;

		address_ofTopNode = &only_node;

		tree_inProcess.top = &tree_inProcess.nodes[1];
	}
	else if (size == 2)
	{
		Node left_n;
		left_n.frequency = frequency_of_signs[1];
		left_n.symbol = code_source[1];
		Node right_n;
		right_n.frequency = frequency_of_signs[0];
		right_n.symbol = code_source[0];


		tree_inProcess.nodes.push_back(left_n);
		tree_inProcess.nodes.push_back(right_n);

		initial_node.right_node = &right_n;
		tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[2];

		initial_node.left_node = &left_n;
		tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[1];

		initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		tree_inProcess.nodes[0].frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;

		address_ofTopNode = &initial_node;
		tree_inProcess.top = &tree_inProcess.nodes[0];
	}
	else
	{
		vector <int> freqs;
		for (int i = 0; i < size - 2; i++)
		{
			freqs.push_back(frequency_of_signs[i]);
		}

		Node left_n;
		left_n.frequency = frequency_of_signs[size - 1];
		left_n.symbol = code_source[size - 1];
		Node right_n;
		right_n.frequency = frequency_of_signs[size - 2];
		right_n.symbol = code_source[size - 2];

		tree_inProcess.nodes.push_back(left_n);
		tree_inProcess.nodes.push_back(right_n);


		if (left_n.frequency <= right_n.frequency)
		{
			initial_node.right_node = &right_n;
			initial_node.left_node = &left_n;

			tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[2];
			tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[1];
		}
		else
		{
			initial_node.left_node = &right_n;
			initial_node.right_node = &left_n;

			tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[2];
			tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[1];
		}

		initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		tree_inProcess.nodes[0].frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;

		Node* temp_leftNode = &initial_node;
		address_ofTopNode = temp_leftNode;
		tree_inProcess.top = &tree_inProcess.nodes[0];

		while (freqs.size() > 0)
		{
			//cout << freqs.size();
			Node* tempNode = new Node;

			Node* tempNode_new = new Node;
			tempNode_new->frequency = freqs[freqs.size() - 1];
			tempNode_new->symbol = code_source[freqs.size() - 1];

			tree_inProcess.nodes.push_back(*tempNode);
			tree_inProcess.nodes.push_back(*tempNode_new);

			if (temp_leftNode->frequency <= tempNode_new->frequency)
			{
				//tempNode->left_node = temp_leftNode;
				tempNode->left_node = address_ofTopNode;
				tempNode->right_node = tempNode_new;

				tree_inProcess.nodes.end()[-2].left_node = tree_inProcess.top;
				tree_inProcess.nodes.end()[-2].right_node = &tree_inProcess.nodes.end()[-1];
			}
			else
			{
				//tempNode->right_node = temp_leftNode;
				tempNode->right_node = address_ofTopNode;
				tempNode->left_node = tempNode_new;

				tree_inProcess.nodes.end()[-2].right_node = tree_inProcess.top;
				tree_inProcess.nodes.end()[-2].left_node = &tree_inProcess.nodes.end()[-1];
			}

			tempNode->frequency = tempNode->right_node->frequency + tempNode->left_node->frequency;
			tree_inProcess.nodes.end()[-2].frequency = tempNode->right_node->frequency + tempNode->left_node->frequency;

			address_ofTopNode = tempNode;
			temp_leftNode = tempNode;

			tree_inProcess.top = &tree_inProcess.nodes.end()[-2];

			freqs.pop_back();
		}

		//cout << endl;
	}

	vector <int> emptyRoad2;
	vector <string> path;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < ti.input.size(); i++)
	{
		decode_s(address_ofTopNode, emptyRoad2, ti.input[i], path);
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
	std::cout << "Czas wykonania: " << duration.count() << " sekund" << std::endl;

	cout << "Srednia dlugosc bitowa kodu wyjsciowego: " << average_bit_length_output_code(frequency_of_signs, path) << endl;

	vector <char> outputData;
	for (int i = 0; i < path.size(); i++) {
		for (int j = 0; j < path[i].size(); j++) {
			outputData.push_back(path[i][j]);
		}
	}
	 
	ofstream binaryFile;
	binaryFile.open(name+".bin", ios::out | ios::binary);
	binaryFile.write(outputData.data(), outputData.size());
	binaryFile.close();
}

void HuffmanCode_makeTreeModel2(vector<std::string> code_source, vector<int> frequency_of_signs, int size2, vector<std::string> arrayofCode, TreeInput ti)
{
	//struct MinHNode* root = buildHfTree(item, freq, size);

	//Node *left_node, *right_node, *top_node;
	Tree_2 tree_inProcess;

	std::string tempC;
	int tempI;
	for (int j = 0; j < size2; j++)
	{
		for (int i = 0; i < size2 - 1; i++)
		{
			if (frequency_of_signs[i] < frequency_of_signs[i + 1])
			{
				tempC = code_source[i + 1];
				tempI = frequency_of_signs[i + 1];
				code_source[i + 1] = code_source[i];
				frequency_of_signs[i + 1] = frequency_of_signs[i];
				code_source[i] = tempC;
				frequency_of_signs[i] = tempI;
			}
		}
	}
	Node_2 initial_node;
	tree_inProcess.nodes.push_back(initial_node);
	/*for (int i = 0; i < size; i++)
	{
		cout << frequency_of_signs[i] << code_source[i] << " ";
	}*/

	Node_2* address_ofTopNode = new Node_2;

	if (size2 == 1)
	{
		Node_2 only_node;
		only_node.frequency = frequency_of_signs[0];
		only_node.symbol = code_source[0];

		tree_inProcess.nodes.push_back(only_node);

		initial_node.right_node = &only_node;
		initial_node.frequency = initial_node.right_node->frequency;

		tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[1];
		tree_inProcess.nodes[0].frequency = tree_inProcess.nodes[0].right_node->frequency;

		address_ofTopNode = &only_node;

		tree_inProcess.top = &tree_inProcess.nodes[1];
	}
	else if (size2 == 2)
	{
		Node_2 left_n;
		left_n.frequency = frequency_of_signs[1];
		left_n.symbol = code_source[1];
		Node_2 right_n;
		right_n.frequency = frequency_of_signs[0];
		right_n.symbol = code_source[0];


		tree_inProcess.nodes.push_back(left_n);
		tree_inProcess.nodes.push_back(right_n);

		initial_node.right_node = &right_n;
		tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[2];

		initial_node.left_node = &left_n;
		tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[1];

		initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		tree_inProcess.nodes[0].frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;

		address_ofTopNode = &initial_node;
		tree_inProcess.top = &tree_inProcess.nodes[0];
	}
	else
	{
		vector <int> freqs;
		for (int i = 0; i < size2; i++)
		{
			freqs.push_back(frequency_of_signs[i]);
		}

		Node_2 left_n;
		left_n.frequency = frequency_of_signs[size2 - 1];
		left_n.symbol = code_source[size2 - 1];
		Node_2 right_n;
		right_n.frequency = frequency_of_signs[size2 - 2];
		right_n.symbol = code_source[size2 - 2];

		tree_inProcess.nodes.push_back(left_n);
		tree_inProcess.nodes.push_back(right_n);


		if (left_n.frequency <= right_n.frequency)
		{
			initial_node.right_node = &right_n;
			initial_node.left_node = &left_n;

			tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[2];
			tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[1];
		}
		else
		{
			initial_node.left_node = &right_n;
			initial_node.right_node = &left_n;

			tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[2];
			tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[1];
		}

		initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		tree_inProcess.nodes[0].frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;

		Node_2* temp_leftNode = &initial_node;
		address_ofTopNode = temp_leftNode;
		tree_inProcess.top = &tree_inProcess.nodes[0];

		while (freqs.size() > 0)
		{
			//cout << freqs.size();
			Node_2* tempNode = new Node_2;

			Node_2* tempNode_new = new Node_2;
			tempNode_new->frequency = freqs[freqs.size() - 1];
			tempNode_new->symbol = code_source[freqs.size() - 1];

			tree_inProcess.nodes.push_back(*tempNode);
			tree_inProcess.nodes.push_back(*tempNode_new);

			if (temp_leftNode->frequency <= tempNode_new->frequency)
			{
				//tempNode->left_node = temp_leftNode;
				tempNode->left_node = address_ofTopNode;
				tempNode->right_node = tempNode_new;

				tree_inProcess.nodes.end()[-2].left_node = tree_inProcess.top;
				tree_inProcess.nodes.end()[-2].right_node = &tree_inProcess.nodes.end()[-1];
			}
			else
			{
				//tempNode->right_node = temp_leftNode;
				tempNode->right_node = address_ofTopNode;
				tempNode->left_node = tempNode_new;

				tree_inProcess.nodes.end()[-2].right_node = tree_inProcess.top;
				tree_inProcess.nodes.end()[-2].left_node = &tree_inProcess.nodes.end()[-1];
			}

			tempNode->frequency = tempNode->right_node->frequency + tempNode->left_node->frequency;
			tree_inProcess.nodes.end()[-2].frequency = tempNode->right_node->frequency + tempNode->left_node->frequency;

			address_ofTopNode = tempNode;
			temp_leftNode = tempNode;

			tree_inProcess.top = &tree_inProcess.nodes.end()[-2];

			freqs.pop_back();
		}

		//cout << endl;
	}

	//cout << frequency_of_signs[0];
	//int arr[MAX_TREE_HT], top = 0;

	//printHCodes(root, arr, top);

	//Node* coutNode = address_ofTopNode;
	for (int i = 0; i < size2; i++)
	{
		int firstchar = code_source[i][0];
		int secondchar = code_source[i][1];
		cout << firstchar;
		cout << secondchar;
	}
	cout << endl;

	vector <int> emptyRoad;
	printTree_2(address_ofTopNode, emptyRoad);

	cout << "\n\n\n";

	for (int i = 0; i < sizeof(arrayofCode); i++)
	{
		decode_2(address_ofTopNode, emptyRoad, arrayofCode[i]);
	}

	std::ofstream myfile_temp;
	myfile_temp.open("coded_withColons.txt");
	myfile_temp.close();
	std::ofstream myfile_temp2;
	myfile_temp2.open("coded.txt");
	myfile_temp2.close();

	vector <int> emptyRoad2;
	for (int i = 0; i < ti.input.size(); i++)
	{
		decode_2s(address_ofTopNode, emptyRoad2, ti.input[i]);
	}
}

void histogram_toCsv(vector<int> a, vector<int> f)
{
	std::ofstream myfile;
	myfile.open("histogram.csv");
	myfile << "Symbol;Frequency\n";
	for (int i = 0; i < f.size(); i++)
	{
		myfile << a[i] << ";" << f[i] << "\n";
	}
	myfile.close();
}

void histogram(vector<int> a, vector<int> f)
{
	int maxValue=0;
	for (int i = 0; i < f.size(); i++)
	{
		if (maxValue < f[i])
		{
			maxValue = f[i];
		}
	}

	int maxSymbolsNumberInHist = 50;

	cout << "____________________________";
	for (int j = 0; j < maxSymbolsNumberInHist; j++)
	{
		cout << "_";
	}
	cout  << endl;

	cout << "Value\t| Frequency\t| Histogram";
	for (int j = 0; j < maxSymbolsNumberInHist - 8; j++)
	{
		cout << " ";
	}
	cout << "|\n";

	int division;

	for (int i = 0; i < f.size(); i++)
	{
		cout << a[i] << "\t| " << f[i] << "\t\t| ";

		division = maxSymbolsNumberInHist * f[i] / maxValue;

		for (int j = 0; j < division; j++)
		{
			cout << "X";
		}
		for (int j = 0; j < maxSymbolsNumberInHist-division; j++)
		{
			cout << "-";
		}

		cout << " |\n";

	}

	cout << "____________________________";
	for (int j = 0; j < maxSymbolsNumberInHist; j++)
	{
		cout << "_";
	}
	cout << endl << endl;
}

void histogram_2(vector<std::string> a, vector<int> f)
{
	int maxValue = 0;
	for (int i = 0; i < f.size(); i++)
	{
		if (maxValue < f[i])
		{
			maxValue = f[i];
		}
	}

	int maxSymbolsNumberInHist = 50;

	cout << "____________________________";
	for (int j = 0; j < maxSymbolsNumberInHist; j++)
	{
		cout << "_";
	}
	cout << endl;

	cout << "Value\t| Frequency\t| Histogram";
	for (int j = 0; j < maxSymbolsNumberInHist - 8; j++)
	{
		cout << " ";
	}
	cout << "|\n";

	int division;

	for (int i = 0; i < f.size(); i++)
	{
		cout << a[i] << "\t| " << f[i] << "\t\t| ";

		division = maxSymbolsNumberInHist * f[i] / maxValue;

		for (int j = 0; j < division; j++)
		{
			cout << "X";
		}
		for (int j = 0; j < maxSymbolsNumberInHist - division; j++)
		{
			cout << "-";
		}

		cout << " |\n";

	}

	cout << "____________________________";
	for (int j = 0; j < maxSymbolsNumberInHist; j++)
	{
		cout << "_";
	}
	cout << endl << endl;
}

float entropy_ofData(vector<int> f)
{
	long float sum = 0;
	for (int i = 0; i < f.size(); i++)
	{
		sum += f[i];
	}

	float prob;
	float entropy = 0;

	for (int i = 0; i < f.size(); i++)
	{
		prob = (float)f[i] / sum;
		if (prob == 0)
		{
			prob = 0.00000000001;
		}
		entropy -= prob * log2(prob);
	}
	return entropy;
}

int main()
{
	//Input string is for example BCAADDDCCACACACKKKKK so:
	vector <string> names = { "barbara", "lena", "boat", "chronometer", "mandril", "peppers", "normalny", "laplacea", "jednorodny" };
	for (int n = 0; n < names.size(); n++) {
		string name = names[n];
		cout << endl << "Procesowanie | " << name << endl;
		SymbolDataModel Sdm;
		TreeInput treeInput;

		if (name == "normalny") treeInput = DataGenerator::normalGenerate(512 * 512);
		else if (name == "laplacea") treeInput = DataGenerator::laplaceGenerate(512 * 512);
		else if (name == "jednorodny") treeInput = DataGenerator::uniformGenerate(512 * 512);
		else treeInput = Sdm.FileRead(name + ".pgm");

		vector<int> array = treeInput.extractUniqueSymbols();
		vector<int> frequency = treeInput.extractFrequencies();

		cout << "Entorpia danych wejsicowych wynosi: " << entropy_ofData(frequency) << endl;

		histogram_toCsv(array, frequency);

		BlockModel bm;
		bm = Sdm.BlockModel2(array, frequency);
		vector<std::string> blockModel2Array = bm.BlockModel2Array;
		vector<int> BlockModel2Frequency = bm.BlockModel2Frequency;
		int size2 = sizeof(blockModel2Array);

		cout << "Entorpia danych wejsicowych modelu blokowego rzedu 2 wynosi: " << entropy_ofData(BlockModel2Frequency) << endl;

		HuffmanCode_makeTree(array, frequency, sizeof(array), array, treeInput, name);

		//HuffmanCode_makeTreeModel2(blockModel2Array, BlockModel2Frequency, size2, blockModel2Array);
	}
}
