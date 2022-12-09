#include <iostream>
#include <vector>
using namespace std;

//#define MAX_TREE_HT 50


class Node {
public:
	char symbol = NULL;
	double frequency = 0;
	Node* left_node = NULL;
	Node* right_node = NULL;
};

class Tree {
public:
	vector <Node*> nodes;
	Node* top = new Node;
};

void printTree(Node* temp, vector <int> whichWayIveGone)
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
	if(temp->left_node == NULL && temp->right_node == NULL)
	{
		cout << "Im terminal leaf with symbol: " << temp->symbol << " and frequancy: " << temp->frequency << " and i've been going trhough the: ";
		for (int i = 0; i < whichWayIveGone.size(); i++)
		{
			cout << whichWayIveGone[i];
		}
		cout << endl;
	}
}

Node* HuffmanCode_makeTree(char code_source[], int frequency_of_signs[], int size)
{
	//struct MinHNode* root = buildHfTree(item, freq, size);

	//Node *left_node, *right_node, *top_node;


	char tempC;
	int tempI;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size-1; i++)
		{
			if (frequency_of_signs[i] < frequency_of_signs[i + 1])
			{
				tempC = code_source[i+1];
				tempI = frequency_of_signs[i+1];
				code_source[i+1] = code_source[i];
				frequency_of_signs[i+1] = frequency_of_signs[i];
				code_source[i] = tempC;
				frequency_of_signs[i] = tempI;
			}
		}
	}
	Node initial_node;
	Tree wholeTree;
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
		initial_node.right_node = &only_node;
		initial_node.frequency = initial_node.right_node->frequency;
		address_ofTopNode = &only_node;
	} 
	else if (size == 2)
	{
		Node left_n;
		left_n.frequency = frequency_of_signs[1];
		left_n.symbol = code_source[1];
		Node right_n;
		right_n.frequency = frequency_of_signs[0];
		right_n.symbol = code_source[0];

		initial_node.right_node = &right_n;
		initial_node.left_node = &left_n;
		initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		address_ofTopNode = &initial_node;
	}
	else
	{
		vector <int> freqs;
		for (int i = 0; i < size-2; i++)
		{
			freqs.push_back(frequency_of_signs[i]);
		}

		Node left_n;
		left_n.frequency = frequency_of_signs[size-1];
		left_n.symbol = code_source[size - 1];
		Node right_n;
		right_n.frequency = frequency_of_signs[size - 2];
		right_n.symbol = code_source[size - 2];

		

		if (left_n.frequency <= right_n.frequency)
		{
			initial_node.right_node = &right_n;
			initial_node.left_node = &left_n;
		}
		else
		{
			initial_node.left_node = &right_n;
			initial_node.right_node = &left_n;
		}

		initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;

		Node* temp_leftNode = &initial_node;
		address_ofTopNode = temp_leftNode;

		while (freqs.size() > 0)
		{
			//cout << freqs.size();
			Node* tempNode = new Node;
			
			Node* tempNode_new = new Node;
			tempNode_new->frequency = freqs[freqs.size() - 1];
			tempNode_new->symbol = code_source[freqs.size() -1];

			if (temp_leftNode->frequency <= tempNode_new->frequency)
			{
				tempNode->left_node = temp_leftNode;
				tempNode->right_node = tempNode_new;
			}
			else
			{
				tempNode->right_node = temp_leftNode;
				tempNode->left_node = tempNode_new;
			}

			tempNode->frequency = tempNode->right_node->frequency + tempNode->left_node->frequency;

			address_ofTopNode = tempNode;
			temp_leftNode = tempNode;
			freqs.pop_back();
		}

		//cout << endl;
	}

	//cout << frequency_of_signs[0];
	//int arr[MAX_TREE_HT], top = 0;

	//printHCodes(root, arr, top);

	//Node* coutNode = address_ofTopNode;
	for (int i = 0; i < size; i++)
	{
		cout << code_source[i];
	}
	cout << endl;

	vector <int> emptyRoad;
	printTree(address_ofTopNode, emptyRoad);

	return address_ofTopNode;
}

int main()
{
	//Input string is for example BCAADDDCCACACACKKKKK so:

	char arrayToCode[] = { 'A', 'B', 'C', 'D'};
	int frequencyOfSigns[] = { 5, 1, 6, 3};
	int size = sizeof(arrayToCode) / sizeof(arrayToCode[0]);
	Node* top_node = HuffmanCode_makeTree(arrayToCode, frequencyOfSigns, size);

}

