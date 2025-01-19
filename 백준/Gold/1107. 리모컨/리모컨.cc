#include <iostream>
#include <string>
using namespace std;

int n, m, answer = -1;
bool broken[10];

bool PushButton(int num) {
	string str = to_string(num);
	for (int i = 0; i < str.length(); i++) {
		if (broken[str[i] - '0'])
			return false;
	}

	return true;
}

int main() {
	cin >> n >> m;
	while (m--) {
		int b; cin >> b;
		broken[b] = true;
	}

	if (n == 100) {
		cout << 0;
		return 0;
	}

	answer = abs(n - 100);
	// 목표 채널은 500000까지, 따라서 그 위의 채널에서 목표 채널로 이동하는 경우도 포함해야한다.
	for (int i = 0; i <= 1000000; i++) {
		if (PushButton(i)) {
			int tmp = abs(i - n) + to_string(i).length(); // 채널 i에서 목표 채널까지 계산
			answer = min(answer, tmp);
		}
	}

	cout << answer;
	return 0;
}
