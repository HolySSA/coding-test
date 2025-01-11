#include <iostream>
using namespace std;

int r, c, answer = -1;
char board[20][20];
bool alphabet[26] = { false, };

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Move(int cr, int cc, int cnt) {
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++) {
		int nr = cr + dr[i];
		int nc = cc + dc[i];

		if (nr < 0 || nc < 0 || nr >= r || nc >= c)
			continue;
		if (alphabet[board[nr][nc] - 'A'])
			continue;

		alphabet[board[nr][nc] - 'A'] = true;
		Move(nr, nc, cnt + 1);
		alphabet[board[nr][nc] - 'A'] = false;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str; cin >> str;
		for (int j = 0; j < c; j++) {
			board[i][j] = str[j];
		}
	}

	alphabet[board[0][0] - 'A'] = true;
	Move(0, 0, 1);
	cout << answer;
	return 0;
}
