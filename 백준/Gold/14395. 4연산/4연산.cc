#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
ll s, t;

void Calculate() {
	queue<pair<ll, string>> q;
	set<ll> visited;
	q.push({ s, "" });
	visited.insert(s);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.first == t) {
			cout << cur.second;
			return;
		}

		ll multiply = cur.first * cur.first;
		ll plus = cur.first + cur.first;

		if (multiply <= t && visited.find(multiply) == visited.end()) {
			q.push({ multiply, cur.second + "*" });
			visited.insert(multiply);
		}
		if (plus <= t && visited.find(plus) == visited.end()) {
			q.push({ plus, cur.second + "+" });
			visited.insert(plus);
		}
		if (cur.first != 0 && visited.find(1) == visited.end()) {
			q.push({ 1, cur.second + "/" });
			visited.insert(1);
		}
	}

	cout << -1;
}

int main() {
	cin >> s >> t;

	if (s == t) {
		cout << 0;
		return 0;
	}

	Calculate();
	return 0;
}