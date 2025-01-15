#include <iostream>
#include <vector>
using namespace std;

int n, k, answer = 0;
vector<int> coins;

int main() {
	cin >> n >> k;
	coins.resize(n);

	for(int i=0;i<n;i++){
		cin >> coins[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		while (coins[i] <= k) {
			k -= coins[i];
			answer++;
		}

		if (k == 0)
			break;
	}

	cout << answer;
	return 0;
}