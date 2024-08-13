#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i=0; i<progresses.size(); i++){
        progresses[i] = 100-progresses[i];
        progresses[i] = progresses[i] % speeds[i] == 0 ? progresses[i] / speeds[i] : progresses[i] / speeds[i] + 1;
    }
    
    int tmp = progresses[0], cnt = 1;
    for(int i=1; i<progresses.size(); i++){
        if(progresses[i] <= tmp)
            cnt++;
        else{
            tmp = progresses[i];
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    
    int sum=0;
    for(int i=0; i<answer.size(); i++)
        sum += answer[i];
    
    if(sum != progresses.size())
        answer.push_back(cnt);
    
    return answer;
}