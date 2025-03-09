#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

int n, k;
bool visited[MAX + 1];

int HideAndSeek() {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k)
			return cnt;

		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push({ cur - 1, cnt + 1 });
			visited[cur - 1] = true;
		}
		if (cur + 1 <= MAX && !visited[cur + 1]) {
			q.push({ cur + 1, cnt + 1 });
			visited[cur + 1] = true;
		}
		if (2 * cur <= MAX && !visited[2 * cur]) {
			q.push({ 2 * cur, cnt + 1 });
			visited[2 * cur] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << HideAndSeek();
	return 0;
}