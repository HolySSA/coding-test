#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 2e9;
int mineralFatigue[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
vector<int> mineralInt;

void digUp(int cur, int sum, vector<int> &picks, vector<string> &minerals) {
    int digUpSum[3] = { 0, };
    int save = 0;
    
    if(minerals.size() <= cur || picks[0] + picks[1] + picks[2] == 0) {
        answer = min(answer, sum);
        return;
    }
    
    for(int i = cur; i < cur + 5; i++){
        if(i >= minerals.size()){
            save = i;
            break;
        }
        
        digUpSum[0] += mineralFatigue[0][mineralInt[i]];
        digUpSum[1] += mineralFatigue[1][mineralInt[i]];
        digUpSum[2] += mineralFatigue[2][mineralInt[i]];
        
        save = i;
    }
    
    for(int i = 0; i < picks.size(); i++) {
        if(picks[i] != 0){
            picks[i]--;
            digUp(save + 1, sum + digUpSum[i], picks, minerals);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
        for(auto &m: minerals) {
            if (m == "diamond")
                mineralInt.push_back(0);
            else if (m == "iron")
                mineralInt.push_back(1);
            else if (m == "stone")
                mineralInt.push_back(2);
        }
    
    digUp(0, 0, picks, minerals);
    
    return answer;
}