#include <iostream>
#include <cmath>
using namespace std;

int d;
long long x, y, r = 0, c = 0;
string str, answer = "";

void Coordinate(long long size) {
	long long half = size / 2;

	for (char cur : str) {
		int quadrant = cur - '0';

		if (quadrant == 1) {
			r += half;
			c += half;
		}
		else if (quadrant == 2) {
			r += half;
		}
		else if (quadrant == 3) {

		}
		else if (quadrant == 4) {
			c += half;
		}

		half /= 2;
	}
}

void Quadrant(long long size) {
	long long half = size / 2;

	while (half > 0) {
		if (r >= half && c >= half) {
			answer += '1';
			r -= half;
			c -= half;
		}
		else if (r >= half && c < half) {
			answer += '2';
			r -= half;
		}
		else if (r < half && c < half) {
			answer += '3';
		}
		else {
			answer += '4';
			c -= half;
		}

		half /= 2;
	}
}

int main() {
	cin >> d >> str;
	cin >> x >> y;

	long long size = (long long)pow(2, d);
	Coordinate(size);

	//cout << r << ' ' << c << '\n';
	r += y;
	c += x;
	//cout << r << ' ' << c << '\n';
	if (r < 0 || c < 0 || r >= size || c >= size) {
		cout << -1;
		return 0;
	}

	Quadrant(size);
	cout << answer;
	return 0;
}
