#include <iostream>
#include <vector>
using namespace std;

int n, num, cur = 1, idx = 0;
vector<int> wait1;
vector<int> wait2;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		wait1.push_back(num);
	}

	while (1) {
		if (idx < n && wait1[idx] == cur) {
			cur++;
			idx++;
		}
		else if (!wait2.empty() && wait2.back() == cur) {
			cur++;
			wait2.pop_back();
		}
		else if (idx < n) {
			wait2.push_back(wait1[idx++]);
		}
		else if (cur > n) {
			cout << "Nice";
			break;
		}
		else {
			cout << "Sad";
			break;
		}
	}

	return 0;
}