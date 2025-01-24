#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t, answer = 0;
vector<pair<int, int>> meetings;

bool Comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin >> n;
	meetings.resize(n);
	for (int i = 0; i < n; i++)	{
		cin >> meetings[i].first >> meetings[i].second;
	}

	sort(meetings.begin(), meetings.end(), Comp);

	t = meetings[0].second;
	answer++;

	for (int i = 1; i < n; i++) {
		if (t <= meetings[i].first) {
			t = meetings[i].second;
			answer++;
		}
	}

	cout << answer;
	return 0;
}