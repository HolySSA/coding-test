#include <iostream>
#include <vector>
using namespace std;

int n, m, low = 0, high = 0;
vector<int> trees;

long long Cut(int height) {
	long long sum = 0;
	for (int t : trees) {
		if (t > height)
			sum += (t - height);
	}

	return sum;
}

int main() {
	cin >> n >> m;
	trees.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		high = max(high, trees[i]);
	}

	while (low <= high) {
		int mid = (low + high) / 2;

		if (Cut(mid) >= m)
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << high;
	return 0;
}
