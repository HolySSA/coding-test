// 1285 동전 뒤집기
#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 1e9;

int n;
int result = INF;
int a[24];
string s;

void func(int cur) {
	if (cur == n + 1) {
		int sum = 0;
		for (int i = 1; i <= 1 << (n - 1); i *= 2) {
			int cnt = 0;

			for (int j = 1; j <= n; j++) {
				if (a[j] & i)
					cnt++;
			}

			sum += min(cnt, n - cnt);
		}

		result = min(result, sum);
		return;
	}

	a[cur] = ~a[cur]; //cur행 뒤집기
	func(cur + 1);
	a[cur] = ~a[cur]; //cur행 뒤집었던거 다시 뒤집음 (그대로 진행)
	func(cur + 1);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int v = 1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') a[i] |= v;
			v *= 2;
		}
	}

	func(1);

	cout << result;
	return 0;
}