#include<iostream>
#include<algorithm>
using namespace std;

int row, col, result;
char board[20][20];
bool alphabet[26];

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void Program(int r, int c, int cnt) {
	result = max(result, cnt);

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= row || nc >= col)
			continue;

		int tmp = board[nr][nc] - 'A';
		if (!alphabet[tmp]) {
			alphabet[tmp] = true;
			Program(nr, nc, cnt + 1);
			alphabet[tmp] = false;
		}
	}
}

int main() {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		string str; cin >> str;

		for (int j = 0; j < col; j++)
			board[i][j] = str[j];
	}

	int start = board[0][0] - 'A';
	alphabet[start] = true;
	Program(0, 0, 1);
	cout << result;

	return 0;
}