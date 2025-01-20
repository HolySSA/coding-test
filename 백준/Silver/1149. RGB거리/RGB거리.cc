#include <iostream>
#include <algorithm>
using namespace std;

int n;
int house[1000][3];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int r, g, b; cin >> r >> g >> b;

		if (i == 0) {
			house[i][0] = r;
			house[i][1] = g;
			house[i][2] = b;
			continue;
		}

		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + r;
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + g;
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + b;
	}

	cout << min({ house[n - 1][0], house[n - 1][1], house[n - 1][2] });
	return 0;
}
