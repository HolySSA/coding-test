#include <iostream>
#include <vector>
using namespace std;

int n, answer;
vector<int> v;
vector<int> dp;

int main() {
	cin >> n;
	v.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	dp[0] = v[0];
	answer = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		answer = max(answer, dp[i]);
	}

	cout << answer;
	return 0;
}
