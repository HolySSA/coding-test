#include<iostream>
#include<algorithm>
using namespace std;

int n, k, result = 0;
string word[50];
bool alphabet[26];

void Teach(int idx, int cnt) {
	if (cnt == k) {
		int canRead = 0;
		for (int i = 0; i < n; i++) {
			bool read = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (alphabet[word[i][j] - 'a'] == false) {
					read = false;
					break;
				}
			}

			if (read)
				canRead++;
		}

		result = max(result, canRead);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alphabet[i] == true)
			continue;

		alphabet[i] = true;
		Teach(i, cnt + 1);
		alphabet[i] = false;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> word[i];

	if (k < 5) {
		cout << 0;
		return 0;
	}

	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;

	k -= 5;

	Teach(0, 0);
	cout << result;

	return 0;
}