// 16946 벽 부수고 이동하기 4
#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int r, c;
};

int n, m;
int map[1000][1000];
bool visited[1000][1000];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Move(int r, int c) {
	queue<Info>q;
	vector<Info>wall;
	q.push({ r, c });
	visited[r][c] = true;

	int cnt = 1;
	while (!q.empty()) {
		int cr = q.front().r;
		int cc = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m)
				continue;

			if (map[nr][nc] == 0 && visited[nr][nc] == false) {
				visited[nr][nc] = true;
				q.push({ nr,nc });
				cnt++;
			}
			// 인접한 벽 저장
			else if (map[nr][nc] != 0 && visited[nr][nc] == false) {
				visited[nr][nc] = true;
				wall.push_back({ nr,nc });
			}
		}
	}
	// 인접한 벽을 기준으로 빈 칸(0) 갯수 더해준다
	for (int i = 0; i < wall.size(); i++) {
		map[wall[i].r][wall[i].c] += cnt;
		visited[wall[i].r][wall[i].c] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && visited[i][j] == false)
				Move(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] % 10;
		}
		cout << '\n';
	}

	return 0;
}