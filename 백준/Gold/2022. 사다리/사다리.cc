#include <iostream>
#include <cmath>
using namespace std;

double x, y, c;

double Calculate(double mid) {
	double h1 = sqrt(x * x - mid * mid);
	double h2 = sqrt(y * y - mid * mid);
	return (h1 * h2) / (h1 + h2);
}

int main() {
	cin >> x >> y >> c;

	double low = 0, high = min(x, y);
	while (high - low > 1e-3) {
		double mid = (low + high) / 2;
		double height = Calculate(mid);

		if (c < height)
			low = mid;
		else
			high = mid;
	}

	cout << low;
	return 0;
}