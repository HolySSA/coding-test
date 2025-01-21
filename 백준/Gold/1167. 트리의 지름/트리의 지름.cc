#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 100001

int v, result = 0, root = 0;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];

void DFS(int idx, int distance) {
	if (visited[idx])
		return;

	if (result < distance) {
		result = distance;
		root = idx;
	}

	visited[idx] = true;
	for (int i = 0; i < tree[idx].size(); i++) {
		int next = tree[idx][i].first;
		int dis = tree[idx][i].second;

		DFS(next, distance + dis);
	}
}

int main() {
	cin >> v;

	for (int i = 0; i < v; i++) {
		int x; cin >> x;
		while (1) {
			int y; cin >> y;
			if (y == -1)
				break;
			int l; cin >> l;

			tree[x].push_back({ y, l });
		}
	}

	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	DFS(root, 0);

	cout << result;

	return 0;
}