// 10610 30
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string n;

bool Comp(char a, char b) {
	return a > b;
}

int main() {
	cin >> n;

	sort(n.begin(), n.end(), Comp);

	if (n.back() != '0') {
		cout << -1;
		exit(0);
	}

	long long sum = 0;
	for (int i = 0; i < n.length(); i++) {
		sum += (long long)(n[i] - '0');
	}

	if (sum % 3 == 0)
		cout << n;
	else
		cout << -1;

	return 0;
}