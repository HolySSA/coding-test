#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int t;
vector<pair<int, int>> test;
bool visited[10000];

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void BFS(int idx) {
    queue<pair<int, int>> q;
    q.push({ test[idx].first, 0 });
    visited[test[idx].first] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == test[idx].second) {
            cout << cur.second << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= 9; j++) {
                string str = to_string(cur.first);
                while (str.size() < 4)
                    str = "0" + str;

                str[i] = j + '0';
                int change = stoi(str);

                if (change > 9999 || change < 1000)
                    continue;
                if (visited[change])
                    continue;
                if (!isPrime(change))
                    continue;

                q.push({ change, cur.second + 1 });
                visited[change] = true;
            }
        }
    }

    cout << "Impossible" << '\n';
}

int main() {
	cin >> t;
	test.resize(t);
	for (int i = 0; i < t; i++) {
		cin >> test[i].first >> test[i].second;
	}

    for (int i = 0; i < t; i++) {
        BFS(i);
        memset(visited, false, sizeof(visited));
    }

	return 0;
}
