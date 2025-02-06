#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
int answer = 0;

void Game(string str) {
	if (str.length() == s.length()) {
		if (str == s)
			answer = 1;

		return;
	}

	if (str.back() == 'A') {
		string tmp = str;
		tmp.pop_back();
		Game(tmp);
	}
	if (str[0] == 'B') {
		reverse(str.begin(), str.end());
		str.pop_back();
		Game(str);
	}
}

int main() {
	cin >> s >> t;
	
	Game(t);
	cout << answer;
	return 0;
}