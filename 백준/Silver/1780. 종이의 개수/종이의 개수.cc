// 1780 종이의 개수
#include<iostream>
using namespace std;

int n, oneNum = 0, minusOneNum = 0, zeroNum = 0;
int paper[2187][2187];

void Cut(int r, int c, int size) {
	bool check = false;
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (paper[i][j] != paper[r][c]) {
				check = true;
				break;
			}
		}
		if (check)
			break;
	}

	if (check) {
		Cut(r, c, size / 3); // 1
		Cut(r + size / 3, c, size / 3); // 2
		Cut(r + (size / 3) * 2, c, size / 3); // 3
		Cut(r, c + size / 3, size / 3); // 4
		Cut(r + size / 3, c + size / 3, size / 3); // 5
		Cut(r + (size / 3) * 2, c + size / 3, size / 3); // 6
		Cut(r, c + (size / 3) * 2, size / 3); // 7
		Cut(r + size / 3, c + (size / 3) * 2, size / 3); // 8
		Cut(r + (size / 3) * 2, c + (size / 3) * 2, size / 3); // 9
	}
	else {
		if (paper[r][c] == -1)
			minusOneNum++;
		else if (paper[r][c] == 0)
			zeroNum++;
		else
			oneNum++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	Cut(0, 0, n);
	cout << minusOneNum << '\n' << zeroNum << '\n' << oneNum;

	return 0;
}