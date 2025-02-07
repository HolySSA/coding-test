#include <iostream>
using namespace std;

// 1. a*b* 일 때 최댓값 = a * b (a가 b번)
// 2. a+b = n => a(n-a) 최댓값 => a = n/2 일 때 최댓값 => 1. 에 의해서 b = n/2 일 때 최댓값
// 3. k <= n(n-1)/2
int n, k;

void AB() {
	if (k == 0) {
		for (int i = 0; i < n - 1; i++) {
			cout << 'B';
		}
		cout << 'A';
	}
	else {
		int cnt = 1, sum = 0;
		for (int i = 0; i < n; i++) {
			if (n - (cnt + i) > 0 && sum + n - (cnt + i) <= k) {
				cout << 'A';
				sum += n - (cnt + i);
				cnt++;
			}
			else
				cout << 'B';
		}
	}
}

int main() {
	cin >> n >> k;
	if (k > n / 2 * (n / 2 + n % 2)) {
		cout << -1;
        return 0;
	}

	AB();
	return 0;
}