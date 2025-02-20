#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;
vector<string> suffix;

int main() {
	cin >> str;
	while (!str.empty()) {
		suffix.push_back(str);
		str.erase(str.begin());
	}

	sort(suffix.begin(), suffix.end());
	for (auto s : suffix) {
		cout << s << '\n';
	}
	return 0;
}
