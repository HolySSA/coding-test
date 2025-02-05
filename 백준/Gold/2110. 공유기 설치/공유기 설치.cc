#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, answer;
vector<int> router;

int main() {
	cin >> n >> c;
	router.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> router[i];
	}

	sort(router.begin(), router.end());

	int low = 1, high = router[n - 1] - router[0];
	while (low <= high) {
		int mid = (low + high) / 2;

		int cnt = 1, cur = router[0];
		for (int i = 1; i < n; i++) {
			if (router[i] - cur >= mid) {
				cnt++;
				cur = router[i];
			}
		}

		if (cnt >= c) {
			answer = max(answer, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << answer;
	return 0;
}