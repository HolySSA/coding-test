
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	int result = -1;
	for (int i = 0; i < n; i++) {
		result = (result < v[i].second - i + 1) ? v[i].second - i + 1 : result;
	}

	cout << result;

	return 0;
}