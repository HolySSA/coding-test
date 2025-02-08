#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer = 0;
vector<int> nums;

int main() {
	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	if (n == 1) {
		cout << nums[0];
		return 0;
	}

	sort(nums.begin(), nums.end());

	// 음수
	int i = 0;
	while (i < n - 1 && nums[i] <= 0 && nums[i + 1] <= 0) {
	answer += nums[i] * nums[i + 1];
	i += 2;
	}
	
	while (i < n && nums[i] <= 0) {
	answer += nums[i];
	i++;
	}
	
	// 양수
	int j = n - 1;
	while (j > 0 && nums[j] > 1 && nums[j - 1] > 1) {
	answer += nums[j] * nums[j - 1];
	j -= 2;
	}
	
	while (j >= 0 && nums[j] > 0) {
	answer += nums[j];
	j--;
	}
	
	cout << answer;
	return 0;
}
