// 그리디
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    for(int i=0; i<reserve.size(); i++){
        for(int j=0; j<lost.size(); j++){
            if(reserve[i] == lost[j]){
                lost.erase(lost.begin()+j);
                reserve.erase(reserve.begin()+i);
                i--, j--;
                answer++;
            }
        }
    }
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i=0; i<reserve.size(); i++){
        for(int j=0; j<lost.size(); j++){
            if(reserve[i]-1 == lost[j] || reserve[i]+1 == lost[j]){
                lost.erase(lost.begin()+j);
                reserve.erase(reserve.begin()+i);
                answer++;
                i--, j--;
                break;
            }
        }
    }
    
    return answer;
}