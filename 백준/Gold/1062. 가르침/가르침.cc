#include <iostream>
#include <vector>
using namespace std;

int n, k, answer = 0;
vector<string> words;
bool alphabet[26];

void Teach(int idx, int cnt) {
	if (cnt == k) {
		int read = 0;
		for (string s : words) {
			bool check = true;
			for (int i = 0; i < s.length(); i++) {
				if (!alphabet[s[i] - 'a']) {
					check = false;
					break;
				}
			}

			if (check)
				read++;
		}

		answer = max(answer, read);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alphabet[i])
			continue;

		alphabet[i] = true;
		Teach(i, cnt + 1);
		alphabet[i] = false;
	}
}

int main() {
	cin >> n >> k;
	words.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	if (k < 5) {
		cout << answer;
		return 0;
	}

	alphabet['a' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;

	Teach(0, 5);
	cout << answer;
	return 0;
}
