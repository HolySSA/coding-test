// 모든 자리의 수의 합이 3의 배수일 경우 3의 배수
// 즉, 만들 수 있는 최대값의 모든 자리 수 합이 3의 배수가 아니면 -1, 3의 배수면 최대값
#include <iostream>
#include <algorithm>
using namespace std;

string n;
long long sum = 0;

bool Comp(char a, char b) {
	return a > b;
}

int main() {
	cin >> n;
	sort(n.begin(), n.end(), Comp);
	
	if (n.back() == '0') {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n.length(); i++) {
		sum += (long long)(n[i] - '0');
	}

	if (sum % 3 == 0)
		cout << n;
	else
		cout << -1;

	return 0;
}
