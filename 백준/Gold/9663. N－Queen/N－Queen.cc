#include <iostream>
using namespace std;

int n, answer = 0;
int board[15][15];

bool Check(int r, int c) {
	// 세로
	for (int i = 0; i < n; i++) {
		if (board[i][c] == 1)
			return false;
	}

	// 왼쪽 위 대각선
	for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
		if (board[r - i][c - i] == 1)
			return false;
	}

	// 오른쪽 위 대각선
	for (int i = 1; r - i >= 0 && c + i < n; i++) {
		if (board[r - i][c + i] == 1)
			return false;
	}

	return true;
}

void NQueen(int row) {
	if (row == n) {
		answer++;
		return;
	}

	for (int col = 0; col < n; col++) {
		if (Check(row, col)) {
			board[row][col] = 1;
			NQueen(row + 1);
			board[row][col] = 0;
		}
	}
}

int main() {
	cin >> n;
	NQueen(0);
	cout << answer;
	return 0;
}
