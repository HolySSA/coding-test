#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, string>> members;

bool Comp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	cin >> n;
	members.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> members[i].first >> members[i].second;
	}

	stable_sort(members.begin(), members.end(), Comp);
	for (int i = 0; i < n; i++) {
		cout << members[i].first << ' ' << members[i].second << '\n';
	}
	return 0;
}