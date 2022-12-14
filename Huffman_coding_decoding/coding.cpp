#include "SymbolDataModel.h"
#include <iostream>
#include <vector>
using namespace std;

//#define MAX_TREE_HT 50


struct Node {
Node* left_node;
Node* right_node;
int isChildOnLeft;
int isChildOnRight;
//public:
	char symbol;
	double frequency;
	Node* getData_left();
	Node* getData_right();
	void setData_left(Node*);
	void setData_right(Node*);
	bool checkLeftChild();
	bool checkRightChild();
	Node()
	{
		symbol = '\0';
		frequency = 0;
		left_node = nullptr;
		right_node = nullptr;
		isChildOnLeft = 0;
		isChildOnRight = 0;
	}
};

bool Node::checkLeftChild()
{
	if (this->isChildOnLeft == 0)
		return false;
	else
		return true;
}

bool Node::checkRightChild()
{
	if (this->isChildOnRight == 0)
		return false;
	else
		return true;
}

Node* Node::getData_left() {
	if(this->isChildOnLeft == 0)
		return this->left_node;
	else
		return nullptr;
}
Node* Node::getData_right() {
	if (this->isChildOnRight == 0)
		return this->right_node;
	else
		return nullptr;
}

void Node::setData_left(Node* NextAddress) {   //DATA GETTER
	this->left_node = NextAddress;
	this->isChildOnLeft = 1;
}
void Node::setData_right(Node* NextAddress) {   //DATA GETTER
	this->right_node = NextAddress;
	this->isChildOnRight = 1;
}

struct Tree {
Node* top;
//public:
	vector <Node> nodes;
	
	void tree_setTop(Node*);
	Node* tree_getTop();
	Node tree_getNode(int);

	Tree()
	{
		top = NULL;
	}
};

Node Tree::tree_getNode(int i)
{
	return this->nodes[i];
}

Node* Tree::tree_getTop() {            //DATA SETTER
	return this->top;
}

void Tree::tree_setTop(Node* NextAddress) {   //DATA GETTER
	this->top = NextAddress;
}

void printTree(Node * temp, vector <int> whichWayIveGone)
{
	//if (temp->left_node != NULL)
	//if (temp->getData_left() != NULL)
	if (temp->isChildOnLeft == 1)
	{
		cout << "Poszedlem w lewo\n";
		whichWayIveGone.push_back(0);
		//printTree(temp->left_node, whichWayIveGone);
		cout << (temp->getData_left()->frequency);
		printTree(temp->getData_left(), whichWayIveGone);
		whichWayIveGone.pop_back();
	}
	//if (temp->right_node != NULL)
	if (temp->isChildOnRight == 1)
	{
		cout << "Poszedlem w prawo\n";
		whichWayIveGone.push_back(1);
		//printTree(temp->right_node, whichWayIveGone);
		printTree(temp->getData_right(), whichWayIveGone);
	}
	//if(temp->left_node == NULL && temp->right_node == NULL)
	if (temp->isChildOnLeft == 0 && temp->isChildOnRight == 0)
	{
		cout << "Im terminal leaf with symbol: " << temp->symbol << " and frequancy: " << temp->frequency << " and i've been going trhough the: ";
		for (int i = 0; i < whichWayIveGone.size(); i++)
		{
			cout << whichWayIveGone[i];
		}
		cout << endl;
	}
}

void printTree_byTree(Tree temp_tree, vector <int> whichWayIveGone)
{
	Node* address_ofTopNode = temp_tree.tree_getTop();

	if (address_ofTopNode->checkLeftChild())
	{
		whichWayIveGone.push_back(0);
		cout << "Poszedlem w lewo\n";
		cout << (temp_tree.tree_getTop()->getData_left()->frequency);
		temp_tree.tree_setTop(address_ofTopNode->getData_left());
		printTree_byTree(temp_tree, whichWayIveGone);

		temp_tree.tree_setTop(address_ofTopNode);
		whichWayIveGone.pop_back();
	}
	if (address_ofTopNode->checkRightChild())
	{
		whichWayIveGone.push_back(1);
		cout << "Poszedlem w prawo\n";
		temp_tree.tree_setTop(address_ofTopNode->getData_right());
		printTree_byTree(temp_tree, whichWayIveGone);
		temp_tree.tree_setTop(address_ofTopNode);
	}
	if (!address_ofTopNode->checkLeftChild() && !address_ofTopNode->checkRightChild())
	{
		cout << "Im terminal leaf with symbol: " << address_ofTopNode->symbol << " and frequancy: " << address_ofTopNode->frequency << " and i've been going trhough the: ";
		for (int i = 0; i < whichWayIveGone.size(); i++)
		{
			cout << whichWayIveGone[i];
		}
		cout << endl;
	}
}


Tree HuffmanCode_makeTree(char code_source[], int frequency_of_signs[], int size)
{
	//struct MinHNode* root = buildHfTree(item, freq, size);

	//Node *left_node, *right_node, *top_node;
	Tree tree_inProcess;

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

		//initial_node.right_node = &only_node;
		//initial_node.frequency = initial_node.right_node->frequency;
		initial_node.setData_right(&only_node);
		initial_node.frequency = initial_node.getData_right()->frequency;

		//tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[1];
		//tree_inProcess.nodes[0].frequency = tree_inProcess.nodes[0].right_node->frequency;
		tree_inProcess.nodes[0].setData_right(&tree_inProcess.nodes[1]);
		tree_inProcess.nodes[0].frequency = tree_inProcess.nodes[0].getData_right()->frequency;

		address_ofTopNode = &only_node;

		//tree_inProcess.top = &tree_inProcess.nodes[1];
		tree_inProcess.tree_setTop(&tree_inProcess.nodes[1]);
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

		//initial_node.right_node = &right_n;
		//tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[2];
		initial_node.setData_right(&right_n);
		tree_inProcess.nodes[0].setData_right(&tree_inProcess.nodes[2]);

		//initial_node.left_node = &left_n;
		//tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[1];
		initial_node.setData_left(&left_n);
		tree_inProcess.nodes[0].setData_left(&tree_inProcess.nodes[1]);

		//initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		//tree_inProcess.nodes[0].frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		initial_node.frequency = initial_node.getData_right()->frequency + initial_node.getData_left()->frequency;
		tree_inProcess.nodes[0].frequency = initial_node.getData_right()->frequency + initial_node.getData_left()->frequency;

		address_ofTopNode = &initial_node;
		//tree_inProcess.top = &tree_inProcess.nodes[0];
		tree_inProcess.tree_setTop(&tree_inProcess.nodes[0]);
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

		tree_inProcess.nodes.push_back(left_n);
		tree_inProcess.nodes.push_back(right_n);
		

		if (left_n.frequency <= right_n.frequency)
		{
			//initial_node.right_node = &right_n;
			//initial_node.left_node = &left_n;
			initial_node.setData_right(&right_n);
			initial_node.setData_left(&left_n);

			//tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[2];
			//tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[1];
			tree_inProcess.nodes[0].setData_right(&tree_inProcess.nodes[2]);
			tree_inProcess.nodes[0].setData_left(&tree_inProcess.nodes[1]);
		}
		else
		{
			//initial_node.left_node = &right_n;
			//initial_node.right_node = &left_n;
			initial_node.setData_left(&right_n);
			initial_node.setData_right(&left_n);

			//tree_inProcess.nodes[0].left_node = &tree_inProcess.nodes[2];
			//tree_inProcess.nodes[0].right_node = &tree_inProcess.nodes[1];
			tree_inProcess.nodes[0].setData_left(&tree_inProcess.nodes[2]);
			tree_inProcess.nodes[0].setData_right(&tree_inProcess.nodes[1]);
		}

		//initial_node.frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		//tree_inProcess.nodes[0].frequency = initial_node.right_node->frequency + initial_node.left_node->frequency;
		initial_node.frequency = right_n.frequency + left_n.frequency;
		tree_inProcess.nodes[0].frequency = right_n.frequency + left_n.frequency;

		Node* temp_leftNode = &initial_node;
		address_ofTopNode = temp_leftNode;
		//tree_inProcess.top = &tree_inProcess.nodes[0];
		tree_inProcess.tree_setTop(&tree_inProcess.nodes[0]);

		while (freqs.size() > 0)
		{
			//cout << freqs.size();
			Node* tempNode = new Node;
			
			Node* tempNode_new = new Node;
			tempNode_new->frequency = freqs[freqs.size() - 1];
			tempNode_new->symbol = code_source[freqs.size() -1];

			tree_inProcess.nodes.push_back(*tempNode);
			tree_inProcess.nodes.push_back(*tempNode_new);

			if (temp_leftNode->frequency <= tempNode_new->frequency)
			{
				//tempNode->left_node = temp_leftNode;
				//tempNode->left_node = address_ofTopNode;
				//tempNode->right_node = tempNode_new;
				tempNode->setData_left(address_ofTopNode);
				tempNode->setData_right(tempNode_new);

				//tree_inProcess.nodes.end()[-2].left_node = tree_inProcess.top;
				//tree_inProcess.nodes.end()[-2].left_node = tree_inProcess.tree_getTop();
				//tree_inProcess.nodes.end()[-2].right_node = &tree_inProcess.nodes.end()[-1];
				tree_inProcess.nodes.end()[-2].setData_left(tree_inProcess.tree_getTop());
				tree_inProcess.nodes.end()[-2].setData_right(&tree_inProcess.nodes.end()[-1]);

			}
			else
			{
				//tempNode->right_node = temp_leftNode;
				//tempNode->right_node = address_ofTopNode;
				//tempNode->left_node = tempNode_new;
				tempNode->setData_right(address_ofTopNode);
				tempNode->setData_left(tempNode_new);

				//tree_inProcess.nodes.end()[-2].right_node = tree_inProcess.top;
				//tree_inProcess.nodes.end()[-2].right_node = tree_inProcess.tree_getTop();
				//tree_inProcess.nodes.end()[-2].left_node = &tree_inProcess.nodes.end()[-1];
				tree_inProcess.nodes.end()[-2].setData_right(tree_inProcess.tree_getTop());
				tree_inProcess.nodes.end()[-2].setData_left(&tree_inProcess.nodes.end()[-1]);
			}

			//tempNode->frequency = tempNode->right_node->frequency + tempNode->left_node->frequency;
			//tree_inProcess.nodes.end()[-2].frequency = tempNode->right_node->frequency + tempNode->left_node->frequency;
			// 
			//tempNode->frequency = tempNode->getData_right()->frequency + tempNode->getData_left()->frequency;
			//tree_inProcess.nodes.end()[-2].frequency = tempNode->getData_right()->frequency + tempNode->getData_left()->frequency;
			

			tempNode->frequency += address_ofTopNode->frequency + tempNode_new->frequency;
			tree_inProcess.nodes.end()[-2].frequency += tree_inProcess.tree_getTop()->frequency + tree_inProcess.nodes.end()[-1].frequency;

			address_ofTopNode = tempNode;
			temp_leftNode = tempNode;

			//tree_inProcess.top = &tree_inProcess.nodes.end()[-2];
			tree_inProcess.tree_setTop(&tree_inProcess.nodes.end()[-2]);

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
	//printTree(address_ofTopNode, emptyRoad);

	printTree_byTree(tree_inProcess, emptyRoad);


	return tree_inProcess;
}

int main()
{
	//Input string is for example BCAADDDCCACACACKKKKK so:

	//SymbolDataModel Sdm;
	//Sdm.FileRead("boat.pgm");

	char arrayToCode[] = { 'A', 'B', 'C', 'D'};
	int frequencyOfSigns[] = { 5, 1, 6, 3};
	int size = sizeof(arrayToCode) / sizeof(arrayToCode[0]);
	Tree tree_test = HuffmanCode_makeTree(arrayToCode, frequencyOfSigns, size);

	vector <int> emptyRoad;
	//printTree(tree_test.top, emptyRoad);
	//printTree_byTree(tree_test, emptyRoad);

}

