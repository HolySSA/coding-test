#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> fillout;
bool solved = false;

bool Check(int r, int c, int val) {
	for (int i = 0; i < 9; i++) {
		// 가로
		if (board[r][i] == val)
			return false;
		// 세로
		if (board[i][c] == val)
			return false;
	}
	// 3*3
	int row = (r / 3) * 3;
	int column = (c / 3) * 3;
	for (int i = row; i < row + 3; i++) {
		for (int j = column; j < column + 3; j++) {
			if (board[i][j] == val)
				return false;
		}
	}

	return true;
}

void Sudoku(int idx) {
	if (solved) return;
	if (idx == fillout.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		solved = true;
		return;
	}
	
	int cr = fillout[idx].first;
	int cc = fillout[idx].second;
	for (int i = 1; i <= 9; i++) {
		if (Check(cr, cc, i)) {
			board[cr][cc] = i;
			Sudoku(idx + 1);
			board[cr][cc] = 0; // 백트레킹 - 중간에 답이 틀릴 경우 대비
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];

			if (board[i][j] == 0)
				fillout.push_back({ i, j });
		}
	}

	Sudoku(0);
	return 0;
}