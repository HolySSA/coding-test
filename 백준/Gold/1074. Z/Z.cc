#include <iostream>
#include <cmath>
using namespace std;

int n, r, c, answer = 0;

void Z(int r, int c, int num) {
	if (num == 1) {
		if (r == 0 && c == 0)
			answer += 0;
		if (r== 0 && c == 1)
			answer += 1;
		if (r == 1 && c == 0)
			answer += 2;
		if (r == 1 && c == 1)
			answer += 3;
		
		return;
	}

	num /= 2;
	if (r < num && c < num) {
		answer += (num * num) * 0;
		Z(r, c, num);
	}
	if (r < num && c >= num) {
		answer += (num * num) * 1;
		Z(r, c - num, num);
	}
	if (r >= num && c < num) {
		answer += (num * num) * 2;
		Z(r - num, c, num);
	}
	if (r >= num && c >= num) {
		answer += (num * num) * 3;
		Z(r - num, c - num, num);
	}
}

int main() {
	cin >> n >> r >> c;
	int num = (int)pow(2, n);

	Z(r, c, num);
	cout << answer;
	return 0;
}