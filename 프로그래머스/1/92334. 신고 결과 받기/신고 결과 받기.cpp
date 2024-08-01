#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, int> report_cnt;
    map<string, set<string>> report_list;

    for(auto s : report){
        int blank = s.find(' ');
        // 신고한 사람
        string from = s.substr(0, blank);
        // 신고받은 사람
        string to = s.substr(blank+1, s.length());

        // set 요소 find ... 중복 거르기
        if(report_list[from].find(to) == report_list[from].end()){
            report_cnt[to]++;
            report_list[from].insert(to);
        }
    }

    for(auto s : id_list){
        int cnt = 0;

        // id_list마다 set에 신고한 id가 저장되어 있으므로
        for(string str : report_list[s]){
            if(report_cnt[str] >= k)
                cnt++;
        }

        answer.push_back(cnt);
    }
    
    return answer;
}