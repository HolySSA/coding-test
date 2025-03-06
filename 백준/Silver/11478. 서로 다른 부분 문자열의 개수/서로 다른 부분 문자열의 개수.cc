#include <iostream>
#include <set>
using namespace std;

string str;
set<string> s;

void Calculate(int idx, int size) {
	if (idx - size < 0)
		return;

	s.insert(str.substr(idx - size, size));
}

int main() {
	cin >> str;

	for (int size = 1; size <= str.length(); size++) {
		for (int i = size; i <= str.length(); i++) {
			Calculate(i, size);
		}
	}

	cout << s.size();
	return 0;
}
