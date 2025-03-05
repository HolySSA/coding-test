#include <iostream>
#include <set>
using namespace std;

int n, m, answer = 0;
string str;
set<string> s;

int main() {
	cin >> n >> m;
	while (n--) {
		cin >> str;
		s.insert(str);
	}

	while (m--) {
		cin >> str;
		if (s.find(str) != s.end())
			answer++;
	}

	cout << answer;
	return 0;
}
