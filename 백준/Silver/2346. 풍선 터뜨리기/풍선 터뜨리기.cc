#include <iostream>
#include <queue>
using namespace std;

int n, num;
deque<pair<int, int>> balloon;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		balloon.push_back({ i + 1, num });
	}

	while (!balloon.empty()) {
		auto cur = balloon.front();
		balloon.pop_front();
		cout << cur.first << ' ';

		if (cur.second > 0) {
			for (int i = 0; i < cur.second - 1; i++) {
				balloon.push_back(balloon.front());
				balloon.pop_front();
			}
		}
		else {
			for (int i = 0; i < -cur.second; i++) {
				balloon.push_front(balloon.back());
				balloon.pop_back();
			}
		}
	}

	return 0;
}