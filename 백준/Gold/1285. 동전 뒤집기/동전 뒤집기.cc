#include <iostream>
#include <vector>

using namespace std;

int n, result = 2e9;
vector<string> coins;

int Reverse(int row) {
	int sum = 0;
	for (int j = 0; j < n; j++) {
		int h_cnt = 0; // 해당 행에서 앞면의 개수
		int t_cnt = 0; // 해당 행에서 뒷면의 개수

		for (int i = 0; i < n; i++) {
			if (((row >> i) & 1) == 1) {
				if (coins[i][j] == 'H')
					t_cnt++;
				else
					h_cnt++;
			}
			else {
				if (coins[i][j] == 'H')
					h_cnt++;
				else
					t_cnt++;
			}
		}

		// 앞면, 뒷면 비교 후 더 적은 면을 더한다. => 뒤집으면 되기 때문.
		sum += min(h_cnt, t_cnt);
	}

	return sum;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		coins.push_back(str);
	}

	// 각 행을 뒤집었을 경우 모두 확인. (n이 3이라면) 1 << 3 (1000 == 8) 
	for (int row = 0; row < (1 << n); row++)
	{
		result = min(result, Reverse(row));
	}

	cout << result;

	return 0;
}
