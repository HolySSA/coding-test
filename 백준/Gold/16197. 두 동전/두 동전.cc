#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int r1, c1, r2, c2, cnt;
};

int n, m;
char board[20][20];

bool visited[20][20][20][20];
vector<pair<int, int>> coins;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool Check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}

void Move() {
	queue<Info> q;
	q.push({ coins[0].first, coins[0].second, coins[1].first, coins[1].second, 0 });
	visited[coins[0].first][coins[0].second][coins[1].first][coins[1].second] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr1 = cur.r1 + dr[i];
			int nc1 = cur.c1 + dc[i];
			int nr2 = cur.r2 + dr[i];
			int nc2 = cur.c2 + dc[i];
			int ncnt = cur.cnt + 1;

			if (ncnt > 10) {
				cout << -1;
				return;
			}

			// 둘 중 하나
			if ((Check(nr1, nc1) && !Check(nr2, nc2)) || (!Check(nr1, nc1) && Check(nr2, nc2))) {
				cout << ncnt;
				return;
			}
			// 둘 다
			if (!Check(nr1, nc1) && !Check(nr2, nc2))
				continue;
			// 방문 체크
			if (visited[nr1][nc1][nr2][nc2])
				continue;
			// 벽 체크
			if (board[nr1][nc1] == '#') {
				nr1 = cur.r1;
				nc1 = cur.c1;
			}
			if (board[nr2][nc2] == '#') {
				nr2 = cur.r2;
				nc2 = cur.c2;
			}

			q.push({ nr1, nc1, nr2, nc2, ncnt });
			visited[nr1][nc1][nr2][nc2];
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'o')
				coins.push_back({ i, j });
		}
	}

	Move();
	return 0;
}