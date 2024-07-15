#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd = 1;
    
    int maxNum = max(n, m);
    for(int i=1; i<=maxNum; i++){
        if(n%i == 0 && m%i == 0)
            gcd = i;
    }
    
    int cm = n*m/gcd;
    
    answer.push_back(gcd);
    answer.push_back(cm);
    
    return answer;
}