#include<iostream>
#include<string>
using namespace std;

int n, m, result = 0;
bool btn[10];

bool Check(int num) {
	string str = to_string(num);

	for (int i = 0; i < str.size(); i++) {
		if (btn[str[i] - '0'])
			return false;
	}

	return true;
}


int main() {
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		btn[num] = true;
	}

	if (n == 100) {
		cout << result;
		return 0;
	}

	result = abs(n - 100);

	for (int i = 0; i <= 1000000; i++) {
		if (Check(i)) {
			int tmp = abs(n - i) + to_string(i).size();
			result = min(result, tmp);
		}
	}

	cout << result;

	return 0;
}