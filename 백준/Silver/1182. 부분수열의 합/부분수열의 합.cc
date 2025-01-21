#include <iostream>
#include <vector>
using namespace std;

int n, s, answer = 0;
vector<int> sums;

void Calculate(int idx, int sum) {
	if (idx == n)
		return;
	if (sum + sums[idx] == s)
		answer++;

	Calculate(idx + 1, sum);
	Calculate(idx + 1, sum + sums[idx]);
}

int main() {
	cin >> n >> s;
	sums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> sums[i];
	}

	Calculate(0, 0);
	cout << answer;
	return 0;
}
