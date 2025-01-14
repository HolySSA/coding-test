#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
map<ll, int> m;
vector<pair<ll, int>> v;

bool Comp(pair<ll, int> a, pair<ll, int> b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num; cin >> num;
		m[num]++;
	}

	for (auto iter : m) {
		v.push_back({ iter.first, iter.second });
	}

	sort(v.begin(), v.end(), Comp);
	cout << v[0].first;
	return 0;
}
