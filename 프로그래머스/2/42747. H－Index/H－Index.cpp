#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(int a, int b){
    return a>b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), Comp);
    
     for(int i=0; i<citations.size(); i++){
        // h 이상
        if(citations[i] >= i+1)
            answer++;
        else
            break;
    }
    
    return answer;
}