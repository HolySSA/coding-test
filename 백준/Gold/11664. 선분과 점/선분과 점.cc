// 11664 선분과 점
#include<iostream>
#include<cmath>
using namespace std;

// 삼분 탐색

struct Pos {
	double x, y, z;
};

Pos A, B, C;

double Distance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
	cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;

	double low = 0, high = 1;
	while (high - low > 0.0000001) {
		Pos Mid1, Mid2;
		double ref1 = (2 * low + high) / 3, ref2 = (low + 2 * high) / 3;

		Mid1.x = B.x * ref1 + A.x * (1 - ref1), Mid2.x = B.x * ref2 + A.x * (1 - ref2);
		Mid1.y = B.y * ref1 + A.y * (1 - ref1), Mid2.y = B.y * ref2 + A.y * (1 - ref2);
		Mid1.z = B.z * ref1 + A.z * (1 - ref1), Mid2.z = B.z * ref2 + A.z * (1 - ref2);

		double dist1 = Distance(C.x, C.y, C.z, Mid1.x, Mid1.y, Mid1.z);
		double dist2 = Distance(C.x, C.y, C.z, Mid2.x, Mid2.y, Mid2.z);

		if (dist1 > dist2)
			low = ref1;
		else
			high = ref2;
	}

	Pos Ans;
	Ans.x = B.x * low + A.x * (1 - low);
	Ans.y = B.y * low + A.y * (1 - low);
	Ans.z = B.z * low + A.z * (1 - low);

	cout << fixed; cout.precision(20);
	cout << Distance(Ans.x, Ans.y, Ans.z, C.x, C.y, C.z) << '\n';

	return 0;
}