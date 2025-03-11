#include <iostream>
#include <vector>
using namespace std;

int n;
char root, child1, child2;
vector<char> tree[26];

void Preorder(char node) {
	if (node == '.')
		return;

	cout << node;
	Preorder(tree[node - 'A'][0]);
	Preorder(tree[node - 'A'][1]);
}

void Inorder(char node) {
	if (node == '.')
		return;

	Inorder(tree[node - 'A'][0]);
	cout << node;
	Inorder(tree[node - 'A'][1]);
}

void Postorder(char node) {
	if (node == '.')
		return;

	Postorder(tree[node - 'A'][0]);
	Postorder(tree[node - 'A'][1]);
	cout << node;
}

int main() {
	cin >> n;

	while (n--) {
		cin >> root >> child1 >> child2;
		tree[root - 'A'].push_back(child1);
		tree[root - 'A'].push_back(child2);
	}

	Preorder('A');
	cout << '\n';
	Inorder('A');
	cout << '\n';
	Postorder('A');
	cout << '\n';
	return 0;
}