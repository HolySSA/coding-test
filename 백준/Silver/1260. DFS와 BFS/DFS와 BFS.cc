#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> edge[1001];
bool visited[1001];

vector<int> dfs;
vector<int> bfs;

void DFS(int vertex) {
	dfs.push_back(vertex);
	visited[vertex] = true;

	for (int i = 0; i < edge[vertex].size(); i++) {
		int next = edge[vertex][i];
		if(!visited[next])
			DFS(next);
	}
}

void BFS() {
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		bfs.push_back(cur);

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (visited[next])
				continue;

			q.push(next);
			visited[next] = true;
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int v_start, v_end; cin >> v_start >> v_end;
		edge[v_start].push_back(v_end);
		edge[v_end].push_back(v_start);
	}

	for (int i = 1; i <= n; i++) {
		sort(edge[i].begin(), edge[i].end());
	}

	DFS(v);
	memset(visited, false, sizeof(visited));
	BFS();

	for (auto i : dfs) {
		cout << i << ' ';
	}
	cout << '\n';
	for (auto i : bfs) {
		cout << i << ' ';
	}
	return 0;
}