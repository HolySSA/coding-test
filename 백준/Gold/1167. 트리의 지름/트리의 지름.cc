#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 100001

struct Info
{
	int vertex, length;
};

int v, answer = -1, root = 0;
vector<Info> tree[MAX];
bool visited[MAX];

void DFS(int idx, int distance) {
	if (visited[idx])
		return;

	if (answer < distance) {
		answer = distance;
		root = idx;
	}

	visited[idx] = true;
	for (int i = 0; i < tree[idx].size(); i++) {
		int next = tree[idx][i].vertex;
		int dis = tree[idx][i].length;

		DFS(next, distance + dis);
	}
}

int main() {
	cin >> v;
	for (int i = 0; i < v; i++) {
		int num; cin >> num;
		while (1) {
			int ver, len; cin >> ver;
			if (ver == -1)
				break;
			cin >> len;
			tree[num].push_back({ ver, len });
		}
	}
	
	DFS(1, 0); // root 찾기
	memset(visited, false, sizeof(visited));
	DFS(root, 0); // root에서 가장 먼 정점 사이 간선합이 지름

	cout << answer;
	return 0;
}
