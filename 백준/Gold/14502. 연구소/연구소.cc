#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, answer = 0;
int map[8][8];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Virus() {
	queue<pair<int, int>> q;

	int tmp[8][8];
	copy(&map[0][0], &map[0][0] + 8 * 8, &tmp[0][0]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 2)
				q.push({ i, j });
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m)
				continue;

			if (tmp[nr][nc] == 0) {
				q.push({ nr, nc });
				tmp[nr][nc] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0)
				cnt++;
		}
	}

	answer = max(answer, cnt);
}

void Wall(int cnt) {
	if (cnt == 3) {
		Virus();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				Wall(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	Wall(0);
	cout << answer;
	return 0;
}