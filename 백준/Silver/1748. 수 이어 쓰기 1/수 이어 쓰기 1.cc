#include <iostream>
using namespace std;

int n;
long long answer = 0;

void Digits(int n) {
    int start = 1;
    int length = 1;

    while (start <= n) {
        long long end = min(n, start * 10 - 1);
        answer += (end - start + 1) * length++;
        start *= 10;
    }
}

int main() {
    cin >> n;
    Digits(n);
    cout << answer;
    return 0;
}
