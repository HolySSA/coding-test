#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		int sum = 0, num = i;

		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}

		if (sum + i == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}