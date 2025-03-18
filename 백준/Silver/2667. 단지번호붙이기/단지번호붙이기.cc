#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
bool visited[25][25];
vector<int> answer;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int House(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	visited[r][c] = true;

	int count = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= n)
				continue;
			if (visited[nr][nc] || map[nr][nc] == 0)
				continue;

			q.push({ nr, nc });
			visited[nr][nc] = true;
			count++;
		}
	}

	return count;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				answer.push_back(House(i, j));
			}
		}
	}
	
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int a : answer) {
		cout << a << '\n';
	}
	return 0;
}
