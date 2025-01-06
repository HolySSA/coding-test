#include<iostream>
#include<string>
using namespace std;

int n;
int title = 666, series = 0;

int main() {
	cin >> n;

	while (series != n) {
		string str = to_string(title);
		for (int i = 0; i < str.length() - 2; i++) {
			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6') {
				series++;

				if (series == n)
					title--;

				break;
			}
		}

		title++;
	}

	cout << title;

	return 0;
}