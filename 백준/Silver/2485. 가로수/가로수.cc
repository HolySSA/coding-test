#include <iostream>
#include <vector>
using namespace std;

int n, gcd, answer = 0;
vector<int> trees;
vector<int> distances;

int GCD(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int main() {
	cin >> n;
	trees.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> trees[i];

		if (i > 0)
			distances.push_back(trees[i] - trees[i - 1]);
	}

	gcd = distances[0];
	for (int i = 1; i < distances.size(); i++) {
		gcd = GCD(gcd, distances[i]);
	}

	for (int i = 0; i < distances.size(); i++) {
		answer += distances[i] / gcd - 1;
	}

	cout << answer;
	return 0;
}