#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while(n > 0){
        int modNum = n%10;
        answer += modNum;
        n /= 10;
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}