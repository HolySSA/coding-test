#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> records;

void Hanoi(int from, int mid, int to, int n) {
	if (n == 1) {
		records.push_back({ from, to });
		return;
	}

	Hanoi(from, to, mid, n - 1);
	records.push_back({ from, to });
	Hanoi(mid, from, to, n - 1);
}

int main() {
	cin >> n;
	Hanoi(1, 2, 3, n);

	cout << records.size() << '\n';
	for (auto r : records) {
		cout << r.first << ' ' << r.second << '\n';
	}
	return 0;
}
