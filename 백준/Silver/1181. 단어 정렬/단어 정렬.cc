#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string word;
vector<string> words;

bool Comp(string a, string b) {
	if (a.length() == b.length())
		return a < b;

	return a.length() < b.length();
}

int main() {
	int n; cin >> n;

	while (n--) {
		cin >> word;
		words.push_back(word);
	}

	sort(words.begin(), words.end(), Comp);
    words.erase(unique(words.begin(), words.end()), words.end());
	
	for (string w : words)
		cout << w << '\n';

	return 0;
}