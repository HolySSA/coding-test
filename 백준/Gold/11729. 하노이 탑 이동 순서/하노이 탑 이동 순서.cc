#include <iostream>
using namespace std;

int n;

void Move(int n, int startRod, int endRod, int bypass)
{
    if (n == 1)
        cout << startRod << ' ' << endRod << '\n';
    else
    {
        Move(n - 1, startRod, bypass, endRod);
        cout << startRod << ' ' << endRod << '\n';
        Move(n - 1, bypass, endRod, startRod);
    }
}

int main() {
    cin >> n;
    // 하노이 원판에서 원판의 갯수가 n일때 최소 횟수: 2^n - 1
    // 1 << n 은 2^n 과 동일 (시프트 연산)
    cout << (1 << n) - 1 << "\n";
    Move(n, 1, 3, 2);

    return 0;
}