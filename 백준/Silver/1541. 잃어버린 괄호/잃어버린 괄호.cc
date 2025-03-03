#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str, tmp = "";
vector<int> number;
vector<char> sign;
int answer = 0;
bool isMinus = false;

int main() {
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i]))
			tmp += str[i];
		else {
			number.push_back(stoi(tmp));
			sign.push_back(str[i]);
			tmp = "";
		}
	}
	number.push_back(stoi(tmp));

	answer = number[0];
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == '-')
			isMinus = true;

		if (isMinus)
			answer -= number[i + 1];
		else
			answer += number[i + 1];
	}

	cout << answer;
	return 0;
}
