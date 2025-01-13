#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> pos;

bool Comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main() {
	cin >> n;
	pos.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i].first >> pos[i].second;
	}

	sort(pos.begin(), pos.end(), Comp);

	for (auto p : pos) {
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}