/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	vector<Node*> childeren;

	Node(int val) : data(val) {}

};

void preorder_traverse(Node* node) {
	if (node == nullptr) {
		return;
	}

	cout << node->data << " ";

	for (Node* child : node->childeren) {
		preorder_traverse(child);
	}
}

void delete_tree(Node* node) {
	if (node == nullptr) {
		return;
	}

	for (Node* child : node->childeren) {
		delete_tree(child);
	}

	cout << node->data << "th node deleted" << '\n';
	delete node;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	Node* n1 = new Node(1);
	Node* n2 = new Node(2);

	n1->childeren.push_back(n2);

	preorder_traverse(n1);

	delete_tree(n1);

	return 0;
}

*/

