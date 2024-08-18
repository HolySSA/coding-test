#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, vector<int>> tmp;
    
    for(auto record : records){
        string num = record.substr(6, 4); // 차 번호
        int time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2)); // 시간
        
        tmp[num].push_back(time);
    }
    
    for(auto c : tmp){
        int sum=0;
        if(c.second.size() % 2 == 1)
            c.second.push_back(23*60 + 59);
        
        for(int i=0; i<c.second.size(); i++){
            if(i%2 == 1)
                sum += c.second[i] - c.second[i-1];
        }
        
        // 기본 시간 체크
        if(sum <= fees[0])
            answer.push_back(fees[1]);
        else{
            int fee = fees[1] + ceil((double)(sum-fees[0]) / fees[2]) * fees[3];
            answer.push_back(fee);
        }
    }
    
    return answer;
}