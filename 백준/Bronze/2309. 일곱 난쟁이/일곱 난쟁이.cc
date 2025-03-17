#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;
vector<int> height(9);

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

	sort(height.begin(), height.end());
	bool check = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			int tmp = height[i] + height[j];

			if (sum - tmp == 100) {
				height.erase(height.begin() + j);
				height.erase(height.begin() + i);

				check = true;
				break;
			}
		}

		if (check)
			break;
	}

	for (int h : height) {
		cout << h << '\n';
	}
	return 0;
}