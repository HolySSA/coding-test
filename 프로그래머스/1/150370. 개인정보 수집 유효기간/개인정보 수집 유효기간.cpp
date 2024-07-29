#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Date_Calcul(string s, vector<int> &date_info){
    string tmp = "";
    for(int i=0; i<s.length(); i++){
        if(i == s.length()-1){
            tmp += s[i];
            date_info.push_back(stoi(tmp));
            break;
        }
        
        if(s[i] == '.'){
            date_info.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
            
        tmp += s[i];
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 유효기간(개월) 저장
    vector<int> limit;
    for(int i=0; i<terms.size(); i++){
        string str = terms[i].substr(terms[i].find(' ')+1, terms[i].length());
        limit.push_back(stoi(str));
    }
    
    vector<int> today_info; // 0 : year, 1 : month, 2 : day
    vector<int> date_info; // 0 : year, 1 : month, 2 : day
    
    // 오늘 연/월/일 구분
    Date_Calcul(today, today_info);
    
    for(int i=0; i<privacies.size(); i++){
        for(int j=0; j<terms.size(); j++){
            if(privacies[i].back() == terms[j][0]){
                string date = privacies[i].substr(0, privacies[i].find(' '));
                // 연/월/일 구분
                Date_Calcul(date, date_info);
                // 날짜 계산
                date_info[1] += limit[j];
                while(date_info[1] > 12){
                    date_info[1] -= 12;
                    date_info[0] += 1;
                }
                
                for(int check=0; check<date_info.size(); check++)
                    cout<<date_info[check];
                cout<<'\n';
                
                // 연 비교
                if(today_info[0] > date_info[0])
                    answer.push_back(i+1);
                else if(today_info[0] < date_info[0]){
                    
                }
                else{
                    // 연도 같으면 월 비교
                    if(today_info[1] > date_info[1])
                        answer.push_back(i+1);
                    else if(today_info[1] < date_info[1]){
                        
                    }
                    else{
                        // 월 같으면 일 비교
                        if(today_info[2] >= date_info[2])
                            answer.push_back(i+1);
                        else if(today_info[2] < date_info[2]){
                            
                        }
                    }
                }
                
                date_info.clear();
                break;
            }
        }
    }
    
    return answer;
}