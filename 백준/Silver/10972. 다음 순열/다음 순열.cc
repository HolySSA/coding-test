#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, idx = -1;
vector<int> v;

int main() {
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		if (v[i] > v[i - 1]) {
			idx = i - 1;
			break;
		}
	}

	if (idx == -1) {
		cout << -1;
		return 0;
	}

	int swapIdx = n - 1;
	while (v[swapIdx] <= v[idx]) {
		swapIdx--;
	}

	swap(v[idx], v[swapIdx]);
	reverse(v.begin() + idx + 1, v.end());

	for (auto i : v) {
		cout << i << ' ';
	}
	return 0;
}
