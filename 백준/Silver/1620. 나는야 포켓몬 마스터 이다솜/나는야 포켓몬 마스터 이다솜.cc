#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
string name;
map<int, string> pokemon;
map<string, int> number;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		pokemon[i] = name;
		number[name] = i;
	}

	while (m--) {
		cin >> name;
		if (isdigit(name[0])) {
			int num = stoi(name);
			cout << pokemon[num] << '\n';
		}
		else {
			cout << number[name] << '\n';
		}
	}

	return 0;
}
