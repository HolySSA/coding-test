#include <iostream>
using namespace std;

long long n, m;

long long Count(long long num, int idx) {
	int cnt = 0;
	for (long long i = idx; i <= num; i *= idx) {
		cnt += num / i;
	}

	return cnt;
}

int main() {
	cin >> n >> m;

	long long five = Count(n, 5) - Count(n - m, 5) - Count(m, 5);
	long long two = Count(n, 2) - Count(n - m, 2) - Count(m, 2);

	cout << min(five, two);
	return 0;
}