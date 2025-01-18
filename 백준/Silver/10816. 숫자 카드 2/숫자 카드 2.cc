#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> cards;

int main() {
	cin >> n;
	while (n--) {
		int num; cin >> num;
		cards[num]++;
	}

	cin >> m;
	while (m--) {
		int num; cin >> num;
		cout << cards[num] << ' ';
	}

	return 0;
}
