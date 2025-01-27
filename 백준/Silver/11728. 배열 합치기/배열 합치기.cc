#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

int main() {
	cin >> n >> m;
	arr.resize(n + m);
	for (int i = 0; i < n + m; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i : arr) {
		cout << i << ' ';
	}
	return 0;
}
