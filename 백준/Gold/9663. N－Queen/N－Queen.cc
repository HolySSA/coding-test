#include<iostream>
using namespace std;

int n, result;
int board[15]; // 가로

bool Check(int row) {
	for (int i = 0; i < row; i++) {
		// 같은 라인에 있거나 대각선이면 false
		if (board[i] == board[row] || abs(board[row] - board[i]) == row - i)
			return false;
	}

	return true;
}

void Nqueen(int node) {
	if (node == n)
		result++;
	else
	{
		for (int i = 0; i < n; i++) {
			board[node] = i;
			if (Check(node))
				Nqueen(node + 1);
		}
	}
}

int main() {
	cin >> n;

	Nqueen(0);
	cout << result;

	return 0;
}