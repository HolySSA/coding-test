#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

bool Comp(vector<string> a, vector<string> b) {
    if(a[0] == b[0])
        return a[1] < b[1];
    
    return a[0] < b[0];
}

int StrtoMinute(string str) {
    istringstream ss(str);
    string substr;
    vector<string> tmp;
    
    while(getline(ss, substr ,':')){
        tmp.push_back(substr);
    }
    
    return stoi(tmp[0]) * 60 + stoi(tmp[1]);
}

int Greedy(vector<vector<string>> book_time) {
    vector<int> time;
    
    // 첫 타임 끝 시간 넣기
    time.push_back(StrtoMinute(book_time[0][1]));
    
    for(int i = 1; i < book_time.size(); i++) {
        // 시작 시간
        int startTime = StrtoMinute(book_time[i][0]);
        
        bool check = false;
        for(int j = 0; j < time.size(); j++) {
            if(startTime >= time[j] + 10) {
                time[j] = StrtoMinute(book_time[i][1]);
                break;
            }
            
            if(j == time.size() - 1)
                check = true;
        }
        
        if(check)
            time.push_back(StrtoMinute(book_time[i][1]));
    }
    
    return time.size();
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end(), Comp);
    
    answer = Greedy(book_time);
    return answer;
}