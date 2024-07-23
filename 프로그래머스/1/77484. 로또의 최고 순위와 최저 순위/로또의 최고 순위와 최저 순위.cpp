#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int tmp = 0, zero_nums = 0;
    for(int i=0; i<lottos.size(); i++){
        if(lottos[i] == 0){
            zero_nums++;
            continue;
        }
        
        // 디폴트 갯수
        if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
            tmp++;
    }
    
    if(tmp+zero_nums < 1)
        answer.push_back(6);
    else
        answer.push_back(7-(tmp+zero_nums));
    
    if(tmp < 1)
        answer.push_back(6);
    else
        answer.push_back(7-tmp);
    
    return answer;
}