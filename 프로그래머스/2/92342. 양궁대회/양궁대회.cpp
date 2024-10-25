#include <string>
#include <vector>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
vector<int> apeach(11, 0);

int scoreDiff = 0;

bool lowScore() {
    for(int i = 10; i >= 0; i--) {
        if(ryan[i] > answer[i])
            return true;
        
        if (ryan[i] < answer[i])
            return false;
    }
}

void compScore() {
    int ryanScore = 0;
    int apeachScore = 0;
    
    for(int i = 0; i < 11; i++) {
        if(ryan[i] > apeach[i]) {
            ryanScore += 10 - i;
            continue;
        }
        
        if(apeach[i] > 0)
            apeachScore += 10 - i;
    }
    
    int diff = ryanScore - apeachScore;
    if(diff > 0) {
        if(scoreDiff < diff) {
            scoreDiff = diff;
            answer = ryan;
        }
        else if(scoreDiff == diff && lowScore()) {
            scoreDiff = diff;
            answer = ryan;
        }
    }
}

void shoot(int idx, int n) {
    if(idx == 11 || n == 0) {
        ryan[10] += n;
        compScore();
        ryan[10] -= n;
        
        return;
    }
    
    if(apeach[idx] < n) {
        ryan[idx] += apeach[idx] + 1;
        shoot(idx + 1, n - (apeach[idx] + 1));
        ryan[idx] -= apeach[idx] + 1;
    }
    
    shoot(idx + 1, n);
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    
    shoot(0, n);

    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}