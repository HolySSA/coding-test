#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    vector<int> tmp;
    while(!score.empty()){
        tmp.push_back(score.back());
        score.pop_back();
        
        if(tmp.size()%m == 0){
            answer += tmp.back()*m;
        }
    }
    
    return answer;
}