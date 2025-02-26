#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> ch;
vector<char> password;
bool visited[26];

bool Vowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void Password(int cnt, int idx) {
	if (cnt == l) {
		int vowel = 0, consonant = 0;

		for (char p : password) {
			if (Vowel(p))
				vowel++;
			else
				consonant++;
		}

		if (vowel >= 1 && consonant >= 2) {
			for (char p : password) {
				cout << p;
			}
			cout << '\n';
		}

		return;
	}

	for (int i = idx; i < c; i++) {
		if (!visited[ch[i] - 'a']) {
			visited[ch[i] - 'a'] = true;
			password.push_back(ch[i]);
			Password(cnt + 1, i);
			password.pop_back();
			visited[ch[i] - 'a'] = false;
		}
	}
}

int main() {
	cin >> l >> c;
	ch.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> ch[i];
	}

	sort(ch.begin(), ch.end());
	Password(0, 0);
	return 0;
}
