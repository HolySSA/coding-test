#include <iostream>
#include <queue>
using namespace std;

struct Info
{
	int r, c, cnt;
};

int n, m;
int maze[100][100];
bool visited[100][100];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Search() {
	queue<Info> q;
	q.push({ 0, 0, 1 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.r == n - 1 && cur.c == m - 1) {
			cout << cur.cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m)
				continue;
			if (visited[nr][nc])
				continue;
			if (maze[nr][nc] == '0')
				continue;

			q.push({ nr, nc, cur.cnt + 1 });
			visited[nr][nc] = true;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			maze[i][j] = str[j];
		}
	}

	Search();
	return 0;
}