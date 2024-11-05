#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

bool Comp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

int startTime(vector<string> plan) {
    istringstream ss(plan[1]);
    string tmp;
    vector<int> v;

    while(getline(ss, tmp, ':')) {
        v.push_back(stoi(tmp));
    }
    
    return v[0] * 60 + v[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string, int>> tmp;
    
    sort(plans.begin(), plans.end(), Comp);
    
    for(auto plan: plans)
        cout<<plan[0]<<' ';
    
    int time = 0;
    for(auto plan: plans) {
        int start = startTime(plan);
        
        while(time < start) {
            if(!tmp.empty()) {
                tmp.back().second--;
                if(tmp.back().second == 0){
                    answer.push_back(tmp.back().first);
                    tmp.pop_back();
                }
            }
            
            time++;
        }
        
        tmp.push_back({ plan[0], stoi(plan[2]) });
    }
    
    while(!tmp.empty()) {
        answer.push_back(tmp.back().first);
        tmp.pop_back();
    }
    
    return answer;
}