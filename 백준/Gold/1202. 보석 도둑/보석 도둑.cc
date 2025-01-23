#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
long long answer = 0;
vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> pq;

int main() {
	cin >> n >> k;
	jewel.resize(n);
	bag.resize(k);

	for (int i = 0; i < n; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && jewel[idx].first <= bag[i]) {
			pq.push(jewel[idx++].second);
		}

		if (!pq.empty()) {
			answer += (long long)pq.top();
			pq.pop();
		}
	}

	cout << answer;
	return 0;
}