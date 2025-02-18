#include <iostream>
using namespace std;

int CountZero(int n) {
    int cnt = 0;
    // 팩토리얼에서 10이 몇 번 곱해지는지 찾는 방법 => 5의 배수 개수 세기.
    // 2는 많기 때문에 고려하지 않아도 됨.
    for (int i = 5; i <= n; i *= 5) {
        cnt += n / i;
    }

    return cnt;
}

int main() {
    int n; cin >> n;

    cout << CountZero(n);
    return 0;
}
