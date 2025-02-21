#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<long long> answer;

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main() {
	cin >> t;
	answer.resize(t);
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> cases(n);

		for (int j = 0; j < n; j++) {
			cin >> cases[j];
		}

		long long sum = 0;
		for (int j = 0; j < cases.size() - 1; j++) {
			for (int k = j + 1; k < cases.size(); k++) {
				sum += GCD(cases[j], cases[k]);
			}
		}

		answer[i] = sum;
	}

	for (auto a : answer) {
		cout << a << '\n';
	}
	return 0;
}
