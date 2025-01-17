// 10815 숫자 카드
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> card;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		card.push_back(tmp);
	}

	sort(card.begin(), card.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		if (binary_search(card.begin(), card.end(), tmp))
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}

	return 0;
}