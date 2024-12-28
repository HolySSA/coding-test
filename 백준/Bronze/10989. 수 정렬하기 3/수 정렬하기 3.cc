// 10989 수 정렬하기 3
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int num[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		num[tmp]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++)
			cout << i << '\n';
	}

	return 0;
}