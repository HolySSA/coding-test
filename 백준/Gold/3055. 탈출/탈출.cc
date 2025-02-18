#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info
{
	int r, c, cnt;
};

int r, c, answer = -1;
pair<int, int> beaver;
pair<int, int> hedgehog;
vector<pair<int, int>> flood;

char forest[50][50];
bool visited[50][50];
int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Move() {
	queue<Info> q;

	// 물 먼저
	for (int i = 0; i < flood.size(); i++) {
		q.push({ flood[i].first, flood[i].second, -1 });
	}
	// 이후 고슴도치
	q.push({ hedgehog.first, hedgehog.second, 0 });
	visited[hedgehog.first][hedgehog.second] = true;


	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.cnt != -1 && forest[cur.r][cur.c] == 'D') {
			answer = cur.cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= r || nc >= c)
				continue;
			if (forest[nr][nc] == 'X' || forest[nr][nc] == '*')
				continue;

			if (cur.cnt == -1) {
				if (forest[nr][nc] == 'D')
					continue;

				if (forest[nr][nc] != '*') {
					q.push({ nr, nc, -1 });
					forest[nr][nc] = '*';
				}
			}
			else {
				if (visited[nr][nc])
					continue;

				q.push({ nr, nc, cur.cnt + 1 });
				visited[nr][nc] = true;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> forest[i][j];

			if (forest[i][j] == 'D')
				beaver.first = i, beaver.second = j;
			if (forest[i][j] == 'S')
				hedgehog.first = i, hedgehog.second = j;
			if (forest[i][j] == '*')
				flood.push_back({ i, j });
		}
	}

	Move();
	if (answer == -1)
		cout << "KAKTUS";
	else
		cout << answer;
	return 0;
}