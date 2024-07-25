#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int same = 0, differ = 0;
    char x = 0;
    for(int i=0; i<s.length(); i++){
        if(x == 0){
            x = s[i];
            same++;
            continue;
        }
        
        if(x == s[i])
            same++;
        else
            differ++;
        
        if(same == differ){
            same = 0, differ = 0;
            x = 0;
            answer++;
        }
    }
    
    if(same != 0)
        answer++;
    
    return answer;
}