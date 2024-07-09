#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    
    while(n>0){
        int num = n%10;
        v.push_back(num);
        n /= 10;
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        answer += v[i]*pow(10, i);
    }
    
    return answer;
}