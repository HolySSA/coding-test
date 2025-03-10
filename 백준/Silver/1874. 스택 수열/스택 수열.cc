#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, num, cur = 1;
bool impossible = false;
stack<int> nums;
vector<char> answer;

int main() {
	cin >> n;

	while (n--) {
		cin >> num;

		if (impossible)
			continue;
		
		while (cur <= num) {
			nums.push(cur++);
			answer.push_back('+');
		}

		if (nums.top() != num)
			impossible = true;

		nums.pop();
		answer.push_back('-');
	}

	if (impossible) {
		cout << "NO";
		return 0;
	}

	for (char a : answer) {
		cout << a << '\n';
	}
	return 0;
}
