#include <iostream>
#include <queue>
#include <string>
using namespace std;

int t, a, b;
bool visited[10000];

void DSLR() {
	queue<pair<int, string>> q;
	fill(visited, visited + 10000, false);
	q.push({ a, ""});
	visited[a] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.first == b) {
			cout << cur.second << '\n';
			return;
		}

		int mod = (2 * cur.first) % 10000;
		if (!visited[mod]) {
			q.push({ mod, cur.second + "D" });
			visited[mod] = true;
		}

		int sub = (cur.first == 0) ? 9999 : cur.first - 1;
		if (!visited[sub]) {
			q.push({ sub, cur.second + "S" });
			visited[sub] = true;
		}

		int lnum = (cur.first % 1000) * 10 + cur.first / 1000;
		if (!visited[lnum]) {
			q.push({ lnum, cur.second + "L" });
			visited[lnum] = true;
		}

		int rnum = (cur.first % 10) * 1000 + cur.first / 10;
		if (!visited[rnum]) {
			q.push({ rnum, cur.second + "R" });
			visited[rnum] = true;
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		DSLR();
	}
	return 0;
}