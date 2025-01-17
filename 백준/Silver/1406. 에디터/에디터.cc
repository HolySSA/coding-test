#include <iostream>
#include <vector>
using namespace std;

string str;
int m;
vector<char> editorL;
vector<char> editorR;

void Editor(char command) {
	switch (command)
	{
		case 'L':
			if (!editorL.empty()) {
				editorR.push_back(editorL.back());
				editorL.pop_back();
			}
			break;
		case 'D':
			if (!editorR.empty()) {
				editorL.push_back(editorR.back());
				editorR.pop_back();
			}
			break;
		case 'B':
			if (!editorL.empty())
				editorL.pop_back();
			break;
		case 'P':
			char c; cin >> c;
			editorL.push_back(c);
			break;
	}
}

int main() {
	cin >> str >> m;

	for (int i = 0; i < str.length();i++) {
		editorL.push_back(str[i]);
	}

	for (int i = 0; i < m; i++) {
		char command; cin >> command;
		Editor(command);
	}

	while (!editorL.empty()) {
		editorR.push_back(editorL.back());
		editorL.pop_back();
	}

	while (!editorR.empty()) {
		cout << editorR.back();
		editorR.pop_back();
	}
	return 0;
}