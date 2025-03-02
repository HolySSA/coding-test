#include <iostream>
#include <vector>
using namespace std;

int n, answer = 0;
vector<int> v;
vector<int> dp;

int main() {
	cin >> n;
	v.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp[i] = v[i];
	}

	answer = dp[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + v[i]);
		}

		answer = max(answer, dp[i]);
	}

	cout << answer;
	return 0;
}