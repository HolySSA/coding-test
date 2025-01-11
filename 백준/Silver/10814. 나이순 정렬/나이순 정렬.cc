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

	stable_sort(members.begin(), members.end(), Comp); // sort 보다 느리지만 상대 순서(정렬 기준이 동일한 경우 처음 순서) 보장
	for (int i = 0; i < n; i++) {
		cout << members[i].first << ' ' << members[i].second << '\n';
	}
	return 0;
}
