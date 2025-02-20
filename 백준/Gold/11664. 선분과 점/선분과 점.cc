#include<iostream>
#include<cmath>
using namespace std;

struct Pos {
	double x, y, z;
};

Pos A, B, C;

double Distance(Pos a, Pos b) {
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

int main() {
	cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;

	// 삼분 탐색
	double low = 0, high = 1;
	while (high - low > 0.0000001) {
		double mid1 = (2 * low + high) / 3;
		double mid2 = (low + 2 * high) / 3;

		Pos Mid1, Mid2;
		Mid1.x = B.x * mid1 + A.x * (1 - mid1), Mid2.x = B.x * mid2 + A.x * (1 - mid2);
		Mid1.y = B.y * mid1 + A.y * (1 - mid1), Mid2.y = B.y * mid2 + A.y * (1 - mid2);
		Mid1.z = B.z * mid1 + A.z * (1 - mid1), Mid2.z = B.z * mid2 + A.z * (1 - mid2);

		double dist1 = Distance(C, Mid1);
		double dist2 = Distance(C, Mid2);

		if (dist1 > dist2)
			low = mid1;
		else
			high = mid2;
	}

	Pos Ans;
	Ans.x = B.x * low + A.x * (1 - low);
	Ans.y = B.y * low + A.y * (1 - low);
	Ans.z = B.z * low + A.z * (1 - low);
	cout << fixed; cout.precision(20);
	cout << Distance(Ans, C);
	return 0;
}