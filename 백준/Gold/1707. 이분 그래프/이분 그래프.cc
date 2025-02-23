#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, v, e, a, b;
vector<int> graph[20001];
int color[20001]; // 0: 미방문 / 1, -1 로 구분
vector<string> answer;

bool BipartiteGraph(int start) {
	queue<int> q;
	q.push(start);
	color[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : graph[cur]) {
			if (color[next] == color[cur])
				return false;
			if (color[next] == 0) {
				color[next] = -color[cur];
				q.push(next);
			}
		}
	}

	return true;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> v >> e;

		// 초기화
		for (int i = 1; i <= v; i++) {
			graph[i].clear();
			color[i] = 0;
		}

		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		bool bipartite = true;
		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				if (!BipartiteGraph(i)) {
					bipartite = false;
					break;
				}
			}
		}

		if (bipartite)
			answer.push_back("YES");
		else
			answer.push_back("NO");
	}

	for (string s : answer) {
		cout << s << '\n';
	}
	return 0;
}