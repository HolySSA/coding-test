#include <iostream>
#include <set>
using namespace std;

int n, m;
string name;
set<string> names;
set<string> answer;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		names.insert(name);
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		if (names.find(name) != names.end())
			answer.insert(name);
	}

	cout << answer.size() << '\n';
	for (auto& n : answer) {
		cout << n << '\n';
	}
	return 0;
}
