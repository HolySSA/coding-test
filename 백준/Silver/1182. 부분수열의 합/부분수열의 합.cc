#include <iostream>
#include <vector>
using namespace std;

int n, s, answer = 0;
vector<int> v;

void Subsequence(int idx, int cnt, int sum) {
	if (idx == n) {
		if (sum == s && cnt > 0)
			answer++;

		return;
	}

	Subsequence(idx + 1, cnt, sum);
	Subsequence(idx + 1, cnt + 1, sum + v[idx]);
}

int main() {
	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	Subsequence(0, 0, 0);
	cout << answer;
	return 0;
}
