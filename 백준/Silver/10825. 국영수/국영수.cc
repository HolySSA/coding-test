#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
	string name;
	int korean, english, math;
};

int n;
vector<Info> v;

bool Comp(Info a, Info b) {
	if (a.korean == b.korean && a.english == b.english && a.math == b.math)
		return a.name < b.name;
	if (a.korean == b.korean && a.english == b.english)
		return a.math > b.math;
	if (a.korean == b.korean)
		return a.english < b.english;
	return a.korean > b.korean;
}

int main() {
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].korean >> v[i].english >> v[i].math;
	}

	sort(v.begin(), v.end(), Comp);
	
	for (auto s : v) {
		cout << s.name << '\n';
	}
	return 0;
}