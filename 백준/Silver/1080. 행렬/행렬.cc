// 1080 행렬
#include <iostream>
using namespace std;

int N, M, cnt = 0;
char matrix1[50][50];
char matrix2[50][50];

void reverse(int x, int y)
{
	for (int i = x; i < x + 3; ++i)
	{
		for (int j = y; j < y + 3; ++j)
		{
			if (matrix1[i][j] == '1')
			{
				matrix1[i][j] = '0';
			}
			else
			{
				matrix1[i][j] = '1';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> matrix1[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> matrix2[i][j];

	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				reverse(i, j);
				cnt++;
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (matrix1[i][j] != matrix2[i][j])
				flag = true;
		}
	}

	if (flag) cout << -1;
	else cout << cnt;
	return 0;
}