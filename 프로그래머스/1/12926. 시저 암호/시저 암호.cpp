#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' ')
            continue;
        
        for(int j=0; j<n; j++){
            if(s[i] == 'z')
            {
                s[i] = 'a';
                continue;
            }
            if(s[i] == 'Z')
            {
                s[i] = 'A';
                continue;
            }
            
            s[i]++;
        }
    }
    
    answer = s;
    
    return answer;
}