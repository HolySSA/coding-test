#include <iostream>
#include <bitset>
using namespace std;

int m, x;
string str;
bitset<21> s;

void Calculate(string str) {
	if (str == "add") {
		cin >> x;
		s.set(x);
	}
	else if (str == "remove") {
		cin >> x;
		s.reset(x);
	}
	else if (str == "check") {
		cin >> x;
		cout << s.test(x) << '\n';
	}
	else if (str == "toggle") {
		cin >> x;
		s.flip(x);
	}
	else if (str == "all") {
		s.set();
	}
	else if (str == "empty") {
		s.reset();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;
	while (m--) {
		cin >> str;
		Calculate(str);
	}
	return 0;
}