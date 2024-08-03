#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    // 첫번째 문자 체크
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0] = toupper(s[0]);
    // 두번째부터
    bool check = false;
    for(int i=1; i<s.length(); i++){   
        if(s[i] == ' '){
            check = true;
            continue;
        }
        else if(check){
            s[i] = toupper(s[i]);
            check = false;
        }
        else
            s[i] = tolower(s[i]);
    }
    
    return s;
}