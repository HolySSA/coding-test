#include <iostream>
using namespace std;

int n, answer = -1;
string before, after;

void Reverse(int idx) {
	before[idx] = before[idx] == '0' ? '1' : '0';
}

void Switch(int idx) {
	if (idx - 1 >= 0)
		Reverse(idx - 1);
	Reverse(idx);
	if (idx + 1 < n)
		Reverse(idx + 1);
}

void Solve(int cnt, int idx) {
	if (idx == n) {
		if (before == after) {
			if (answer == -1)
				answer = cnt;
			else
				answer = min(answer, cnt);
		}

		return;
	}
	
	if (before[idx - 1] == after[idx - 1])
		Solve(cnt, idx + 1);
	else {
		Switch(idx);
		Solve(cnt + 1, idx + 1);
	}
}

int main() {
	cin >> n;
	cin >> before >> after;
	string backtracking = before;
	// 첫번째 전구 그대로
	Solve(0, 1);
	// 첫번째 전구 바꾸고
	if (answer == -1) {
		before = backtracking;
		Switch(0);
		Solve(1, 1);
	}

	cout << answer;
	return 0;
}