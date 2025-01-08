#include <iostream>
#include <string>
using namespace std;

string input, num;
int answer = 0;
bool isMinus = false;

int main() {
	cin >> input;

	for (int i = 0; i <= input.length(); i++) {
		// - 뒤에 -가 나와도
		// - ( ... ) 여기까지 계산하고 뒤에 - () 를 처리하면 다 -로 처리 가능
		if (input[i] == '+' || input[i] == '-' || i == input.length()) {
			if (isMinus)
				answer -= stoi(num);
			else
				answer += stoi(num);

			num = "";
		}
		else
			num += input[i];

		if (input[i] == '-')
			isMinus = true;
	}

	cout << answer;
	return 0;
}