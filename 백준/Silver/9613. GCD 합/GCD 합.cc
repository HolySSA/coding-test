#include <iostream>
#include <cstring>
using namespace std;

int t;
long long sum = 0;
int num[100];

int GCD(int x, int y) {
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
}

int main() {
	cin >> t;
	
	while (t--) {
		memset(num, 0, sizeof(num));
		sum = 0;

		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			num[i] = tmp;
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += GCD(num[i], num[j]);
			}
		}
		
		cout << sum << '\n';
	}

	return 0;
}
