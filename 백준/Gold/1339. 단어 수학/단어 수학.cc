#include <iostream>
#include <algorithm>
using namespace std;

int n, answer = 0;
int alphabet[26];

bool Comp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;

	while (n--) {
		string str; cin >> str;
		int pow = 1;
		for (int i = str.length() - 1; i >= 0; i--) {
			alphabet[str[i] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(alphabet, alphabet + 26, Comp);

	int num = 9;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0)
			break;

		answer += alphabet[i] * num--;
	}

	cout << answer;
	return 0;
}