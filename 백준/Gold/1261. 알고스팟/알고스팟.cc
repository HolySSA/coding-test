#include <iostream>
#include <deque>
using namespace std;

int n, m;
int spot[101][101];
int wall[101][101];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void AlgoSpot() {
	deque<pair<int, int>> dq;
	dq.push_front({ 1, 1 });
	wall[1][1] = 0;

	while (!dq.empty()) {
		int r = dq.front().first;
		int c = dq.front().second;
		dq.pop_front();

		if (r == n && c == m) {
			cout << wall[n][m];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr <= 0 || nc <= 0 || nr > n || nc > m)
				continue;

			int naoj = wall[r][c] + spot[nr][nc];
			if (naoj < wall[nr][nc]) {
				wall[nr][nc] = naoj;
				if (spot[nr][nc] == 0)
					dq.push_front({ nr, nc });
				else 
					dq.push_back({ nr, nc });
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			spot[i][j + 1] = str[j] - '0';
		}
	}

	fill(&wall[0][0], &wall[0][0] + sizeof(wall) / sizeof(int), 10000);
	AlgoSpot();
	return 0;
}