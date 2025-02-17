#include <iostream>
#include <vector>
using namespace std;

int n, answer = 0, farNode;
bool visited[10001];
vector<pair<int, int>> trees[10001];

void Diameter(int idx, int sum) {
	visited[idx] = true;

	if (sum > answer) {
		answer = sum;
		farNode = idx;
	}

	for (auto next : trees[idx]) {
		if (!visited[next.first])
			Diameter(next.first, sum + next.second);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int node1, node2, edge; cin >> node1 >> node2 >> edge;
		trees[node1].push_back({ node2, edge });
		trees[node2].push_back({ node1, edge });
	}

	Diameter(1, 0);
	fill(begin(visited), end(visited), false);
	Diameter(farNode, 0);

	cout << answer;
	return 0;
}