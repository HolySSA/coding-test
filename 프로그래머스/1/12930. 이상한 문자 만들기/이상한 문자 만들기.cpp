#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int check = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' ')
        {
            check = 0;
            answer += ' ';
            continue;
        }
        
        if(check % 2 == 0)
            answer += toupper(s[i]);
        else
            answer += tolower(s[i]);
        
        check++;
    }
    
    return answer;
}