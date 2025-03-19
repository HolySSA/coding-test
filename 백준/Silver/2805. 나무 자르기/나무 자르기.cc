// 2805 나무 자르기
#include<iostream>
#include<vector>
using namespace std;

int n, m, maxheight = 0;
vector<int> height;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	height.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
		maxheight = max(maxheight, height[i]);
	}

	int left = 0;
	int right = maxheight;

	int result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		long long total = 0;
		for (auto i = 0; i < n; i++) {
			if (height[i] > mid)
				total += height[i] - mid;
		}
		if (total < m) {
			right = mid - 1;
		}
		else {
			result = mid;
			left = mid + 1;
		}
	}
	cout << result;

	return 0;
}