#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> third;
    
    while(n>0){
        third.push_back(n%3);
        n /= 3;
    }
    
    int mul = 1;
    for(int i=third.size()-1; i>=0; i--){
        answer += third[i] * mul;
        mul *= 3;
    }
    
    return answer;
}