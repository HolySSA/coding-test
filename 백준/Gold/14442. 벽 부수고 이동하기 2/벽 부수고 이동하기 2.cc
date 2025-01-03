#include <iostream>
#include <queue>
using namespace std;

struct Info
{
	int r;
	int c;
	int wall;
};

int n, m, k;
int map[1000][1000];
int result[1000][1000];
bool visited[1000][1000][10];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Move() {
	queue<Info> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = true;
	result[0][0] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.r == n - 1 && cur.c == m - 1) {
			cout << result[cur.r][cur.c];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m)
				continue;
			if (visited[nr][nc][cur.wall])
				continue;

			if (map[nr][nc] == 0) {
				visited[nr][nc][cur.wall] = true;
				result[nr][nc] = result[cur.r][cur.c] + 1;
				q.push({ nr, nc, cur.wall });
			}
			if (map[nr][nc] == 1 && cur.wall < k) {
				visited[nr][nc][cur.wall + 1] = true;
				result[nr][nc] = result[cur.r][cur.c] + 1;
				q.push({ nr, nc, cur.wall + 1 });
			}
		}
	}

	cout << -1;
	return;
}

int main() {
	cin >> n >> m >> k;

	if (n == 1 && m == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	Move();
	return 0;
}