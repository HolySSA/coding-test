#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int sum = 0, tmp = x;
    
    while(tmp > 0){
        sum += tmp%10;
        tmp /= 10;
    }
    
    if(x % sum == 0){
        answer = true;
    }
    else{
        answer = false;
    }
    
    return answer;
}