#include <iostream>
#include <cmath>
using namespace std;

double x, y, c;

double Prediction (double distance) {
	double h1 = sqrt(x * x - distance * distance);
	double h2 = sqrt(y * y - distance * distance);
	
	return (h1 * h2) / (h1 + h2); // c 예측
}

int main() {
	cin >> x >> y >> c;

	double low = 0;
	double high = min(x, y); // 어자피 ?는 x, y보다 작다

	while (high - low > 0.001) {
		double mid = (low + high) / 2.0;

		if (Prediction(mid) >= c)
			low = mid;
		else
			high = mid;
	}

	cout << low;
	return 0;
}