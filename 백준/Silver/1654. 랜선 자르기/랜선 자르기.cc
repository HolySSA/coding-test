#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
long long answer = 0;
vector<int> cable;

int Cut(int size) {
	int cnt = 0;
	for (auto c : cable) {
		cnt += c / size;
	}

	return cnt;
}

int main() {
	cin >> k >> n;
	cable.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> cable[i];
	}

	long long low = 1, high = *max_element(cable.begin(), cable.end());
	while (low <= high) {
		long long mid = (low + high) / 2;

		long long cnt = Cut(mid);
		if (cnt >= n) {
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