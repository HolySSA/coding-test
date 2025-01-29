#include <iostream>
#include <cstring>
using namespace std;

int n;
char star[3073][6145];

void Star(int r, int c, int num) {
	if (num == 3) {
		star[r][c] = '*'; // *
		star[r + 1][c - 1] = '*'; // * *
		star[r + 1][c] = ' ';
		star[r + 1][c + 1] = '*';
		star[r + 2][c - 2] = '*'; // *****
		star[r + 2][c - 1] = '*';
		star[r + 2][c] = '*';
		star[r + 2][c + 1] = '*';
		star[r + 2][c + 2] = '*';
	}
	else {
		Star(r, c, num / 2);
		Star(r + num / 2, c - num / 2, num / 2);
		Star(r + num / 2, c + num / 2, num / 2);
	}
}

int main() {
	cin >> n;
	memset(star, ' ', sizeof(star));

	Star(1, n, n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n * 2; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
	return 0;
}