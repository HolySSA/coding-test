#include <iostream>
#include <queue>
using namespace std;

int n, m, player = 1;
int board[100];
bool visited[100];

void Dice() {
	queue<pair<int, int>> q;
	q.push({ player, 0 });
	visited[player] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		// 주사위
		for (int i = 1; i <= 6; i++) {
			int next = cur.first + i;
			if (next == 100) {
				cout << cur.second + 1;
				return;
			}

			if (next > 100)
				continue;
			if (visited[next])
				continue;

			if (board[next] != 0)
				next = board[next];

			q.push({ next, cur.second + 1 });
			visited[next] = true;
		}
	}
}

int main() {
	cin >> n >> m;
	while (n--) {
		int x, y; cin >> x >> y;
		board[x] = y;
	}
	while (m--) {
		int u, v; cin >> u >> v;
		board[u] = v;
	}

	Dice();
	return 0;
}