#include <iostream>
using namespace std;

int a, b, v, cur = 0, answer = 1;

int main() {
    cin >> a >> b >> v;

    answer += (v - a) / (a - b);

    // 낮에 도착일 경우 1일 더
    if ((v - a) % (a - b) != 0)
        answer++;

    if (a == v)
        cout << 1;
    else
        cout << answer;
	return 0;
}
