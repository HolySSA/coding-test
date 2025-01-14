// 11652 카드
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<long long> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	long long result = vec[0];
	int max = 0, cnt = 0;
	for (int i = 1; i < n; i++)
	{
		// 정렬했으므로
		if (vec[i] == vec[i - 1])
		{
			cnt++;
			if (cnt > max)
			{
				max = cnt;
				result = vec[i];
			}
		}
		else
			cnt = 0;
	}

	cout << result;

	return 0;
}