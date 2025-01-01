#include <iostream>
using namespace std;

int n, m, k;
int team = 0;

int main() {
	cin >> n >> m >> k;

	while (n + m - 3 >= k) {
		if (n < 2 || m < 1)
			break;

		n -= 2;
		m -= 1;
		team++;
	}

	cout << team;
	return 0;
}