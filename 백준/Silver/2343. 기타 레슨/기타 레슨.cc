#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> lecture;

bool Bluray(int size) {
	int cnt = 1, sum = 0;
	for (int length : lecture) {
		if (length > size)
			return false;

		if (sum + length > size) {
			cnt++;
			sum = length;
		}
		else {
			sum += length;
		}
	}

	return cnt <= m;
}

int main() {
	cin >> n >> m;
	lecture.resize(n);

	int low = 0, high = 0;
	for (int i = 0; i < n; i++) {
		cin >> lecture[i];
		low = max(low, lecture[i]);
		high += lecture[i];
	}

	while (low <= high) {
		int mid = (low + high) / 2;

		if (Bluray(mid))
			high = mid - 1;
		else
			low = mid + 1;
	}

	cout << low;
	return 0;
}