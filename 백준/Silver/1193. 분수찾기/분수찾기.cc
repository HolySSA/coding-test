#include <iostream>
using namespace std;

int x, line = 1;

int main() {
	cin >> x;

	while (line < x) {
		x -= line;
		line++;
	}

	if (line % 2 == 0)
		cout << x << '/' << line + 1 - x;
	else
		cout << line + 1 - x << '/' << x;

	return 0;
}