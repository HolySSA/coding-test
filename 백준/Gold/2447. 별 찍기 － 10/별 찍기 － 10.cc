#include <iostream>
using namespace std;

int n;

void Star(int r, int c, int num) {
	if ((r / num) % 3 == 1 && (c / num) % 3 == 1)
		cout << ' ';
	else if ((num / 3 == 0))
		cout << '*';
	else
		Star(r, c, num / 3);

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Star(i, j, n);
		}
		cout << '\n';
	}
	return 0;
}