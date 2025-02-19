#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int r, c, cnt;
};

int m, n, answer = -1;
int tomato[1000][1000];
vector<pair<int, int>> ripens;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Ripen() {
	queue<Info> q;
	for (auto r : ripens) {
		q.push({ r.first, r.second, 0 });
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.cnt > answer)
			answer = cur.cnt;

		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m)
				continue;
			if (tomato[nr][nc] != 0)
				continue;

			tomato[nr][nc] = 1;
			q.push({ nr, nc, cur.cnt + 1 });
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
				ripens.push_back({ i, j });
		}
	}

	Ripen();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << answer;
	return 0;
}