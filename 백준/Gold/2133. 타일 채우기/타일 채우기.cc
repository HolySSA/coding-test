#include <iostream>
using namespace std;

int n;
int dp[31];

int main() {
	cin >> n;
	if (n % 2 != 0) {
		cout << 0;
		return 0;
	}

	dp[0] = 1, dp[2] = 3;
	for (int i = 2; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2]; // 3*(i-2)까지 채운 후 3*2 타일 추가

		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2; // 겹치지 않는 타일 추가
		}
	}

	cout << dp[n];
	return 0;
}
