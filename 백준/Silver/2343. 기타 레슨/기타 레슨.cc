#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> video;

bool canDivide(int maxSize) {
	int cnt = 1, sum = 0;
	for (int length : video) {
		if (sum + length > maxSize) {
			cnt++;
			sum = 0;
		}

		sum += length;
		if (length > maxSize)
			return false;
	}

	return cnt <= m;
}

int main() {
	cin >> n >> m;
	video.resize(n);

	int low = 0, high = 0;
	for (int i = 0; i < n; i++) {
		cin >> video[i];
		low = max(low, video[i]);
		high += video[i];
	}

	int answer = high;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (canDivide(mid)) {
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