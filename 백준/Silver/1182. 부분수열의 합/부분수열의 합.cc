#include <iostream>
using namespace std;

int n, s, result = 0;
int num[20];

void Plus(int idx, int sum) {
	if (idx == n)
		return;
	if (sum + num[idx] == s)
		result++;

	Plus(idx + 1, sum);
	Plus(idx + 1, sum + num[idx]);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	Plus(0, 0);

	cout << result;
	return 0;
}