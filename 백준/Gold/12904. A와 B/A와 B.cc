#include <iostream>
#include <algorithm>
using namespace std;

string s, t;

bool Game() {
    while (s.length() < t.length()) {
        if (t.back() == 'A')
            t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    return s == t;
}

int main() {
	cin >> s >> t;
	
    if (Game())
        cout << 1;
    else
        cout << 0;
	return 0;
}