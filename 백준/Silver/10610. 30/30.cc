#include <iostream>
#include <algorithm>
using namespace std;

string n;
int sum = 0;

bool Comp(char a, char b) {
	return a > b;
}

int main() {
	cin >> n;
	sort(n.begin(), n.end(), Comp);

	// 30 => 2와 5와 3의 배수
	// 2의 배수: 2, 4, 6, 8, 0 으로 끝남
	// 5의 배수: 5, 0 으로 끝남
	// 3의 배수: 모든 자릿수의 합이 3의 배수
	if (n.back() != '0') {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n.length(); i++) {
		sum += n[i] - '0';
	}

	if (sum % 3 == 0)
		cout << n;
	else
		cout << -1;

	return 0;
}
