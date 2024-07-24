#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int x_cnt[10] = {0, };
    int y_cnt[10] = {0, };
    
    for(int i=0; i<X.length(); i++)
        x_cnt[X[i]-'0']++;
    for(int i=0; i<Y.length(); i++)
        y_cnt[Y[i]-'0']++;
    
    for(int i=9; i>=0; i--){
        int check_cnt = min(x_cnt[i], y_cnt[i]);
        
        while(check_cnt>0){
            answer += to_string(i);
            check_cnt--;
        }
    }
    
    if(answer == "")
        answer = "-1";
    
    if(answer[0] == '0')
        answer = '0';
    
    return answer;
}