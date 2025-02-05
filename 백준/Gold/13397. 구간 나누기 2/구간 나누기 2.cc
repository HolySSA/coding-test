#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, answer = 0;
vector<int> arr;

bool Check(int size) {
	int cnt = 1, minimum = arr[0], maximum = arr[0];
	for (int i = 1; i < n; i++) {
		minimum = min(minimum, arr[i]);
		maximum = max(maximum, arr[i]);
	
		if (maximum - minimum > size) {
			cnt++;
			minimum = arr[i], maximum= arr[i];
		}
	}
	
	return cnt <= m;
}

int main() {
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int low = 0, high = *max_element(arr.begin(), arr.end());
	while (low <= high) {
		int mid = (low + high) / 2;

		if (Check(mid)) {
			answer = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << answer;
	return 0;
}