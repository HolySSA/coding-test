#include <iostream>
using namespace std;

#define MOD 1000000000

int n, k;
int dp[201][201];

int main() {
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1; // 1개로 i를 만드는 방법
	}

	for (int cnt = 2; cnt <= k; cnt++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				dp[cnt][i] = (dp[cnt][i] + dp[cnt - 1][i - j]) % MOD;
			}
		}
	}

	cout << dp[k][n];
	return 0;
}
