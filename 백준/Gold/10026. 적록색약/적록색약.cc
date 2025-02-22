#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, normal = 0, blind = 0;
char board[100][100];
bool visited[100][100];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Area(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	visited[r][c] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= n)
				continue;
			if (visited[nr][nc])
				continue;

			if (board[cur.first][cur.second] == board[nr][nc]) {
				q.push({ nr, nc });
				visited[nr][nc] = true;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				Area(i, j);
				normal++;
			}
		}
	}

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				Area(i, j);
				blind++;
			}
		}
	}

	cout << normal << ' ' << blind;
	return 0;
}