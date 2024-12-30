#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;

int main() {
	int n; cin >> n;
	vector<int> atm;

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		atm.push_back(t);
	}

	sort(atm.begin(), atm.end());

	for (int i = 0; i < n; i++) {
		sum += atm[i] * (n - i);
	}

	cout << sum;

	return 0;
}