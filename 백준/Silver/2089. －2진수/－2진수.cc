#include <iostream>
using namespace std;

int n;
string answer;

int main() {
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	while (n != 0) {
		if (n % (-2) == 0) {
			answer = '0' + answer;
			n /= -2;
		}
		else {
			answer = '1' + answer;
			n = (n - 1) / -2;
		}
	}

	cout << answer;
	return 0;
}