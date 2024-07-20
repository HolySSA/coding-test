#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Comp(int a, int b){
    return a>b;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> rank;
    for(int i=0; i<score.size(); i++){
        if(rank.size() < k){
            rank.push_back(score[i]);
        }
        else{
            if(rank.back() < score[i]){
                rank.pop_back();
                rank.push_back(score[i]);
            }
        }
        
        sort(rank.begin(), rank.end(), Comp);
        answer.push_back(rank.back());
    }
    
    return answer;
}