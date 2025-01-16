#include <iostream>
#include <map>
using namespace std;

int a, b;
map<int, bool> m;

int main() {
	cin >> a >> b;

	for (int i = 0; i < a + b; i++) {
		int num; cin >> num;
		
		if (m[num])
			m.erase(num);
		else
			m[num] = true;
	}

	cout << m.size();
	return 0;
}
