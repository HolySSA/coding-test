#include <iostream>
#include <vector>
using namespace std;

int n;
int money[16];
vector<pair<int, int>> consult;

int main() {
	cin >> n;
	consult.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> consult[i].first >> consult[i].second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + consult[i].first; j <= n; j++) {
			money[j] = max(money[j], consult[i].second + money[i]);
		}
	}

	cout << money[n];
	return 0;
}
