#include <iostream>
#include <string>
using namespace std;

int n, k, digits = 1;

long long Length(int num) {
	int digits = 1;
	long long len = 0;
	for (int i = 1; i <= num; i *= 10) {
		int end = i * 10 - 1;
		if (end > num)
			end = num;

		// (9-1 +1) * 1
		// (99-10 +1) * 2
		// (999-100 +1) * 3
		len += (long long)((end - i + 1) * digits);
		digits++;
	}

	return len;
}

int main() {
	cin >> n >> k;

	long long len = Length(n);
	if (len < k) {
		cout << -1;
		return 0;
	}

	int low = 1, high = n;
	while (low <= high) {
		int mid = (low + high) / 2;

		long long mid_len = Length(mid);
		if (mid_len < k)
			low = mid + 1;
		else
			high = mid - 1;
	}
	
	len = Length(low - 1);
	string num = to_string(low);
	cout << num[k - len - 1];
	return 0;
}