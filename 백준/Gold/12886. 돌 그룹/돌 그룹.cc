#include <iostream>
#include <queue>
using namespace std;

int a, b, c, sum;
bool visited[1500][1500];

void Group() {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int tmp[3] = { cur.first, cur.second, sum - cur.first - cur.second };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tmp[i] < tmp[j]) {
					int num1 = tmp[i] + tmp[i];
					int num2 = tmp[j] - tmp[i];

					if (visited[num1][num2])
						continue;

					q.push({ num1, num2 });
					visited[num1][num2] = true;
				}
			}
		}
	}
}

int main() {
	cin >> a >> b >> c;

	sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}

	Group();
	cout << visited[sum / 3][sum / 3];
	return 0;
}