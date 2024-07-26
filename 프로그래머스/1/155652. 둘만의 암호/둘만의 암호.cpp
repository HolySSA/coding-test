#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    set<char> set_s;
    
    for(int i=0; i<skip.length(); i++)
        set_s.insert(skip[i]);
    
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        for(int j=1; j<=index; j++){
            c++;
            if(c == 'z'+1)
                c = 'a';
            
            while(set_s.find(c) != set_s.end()){
                c++;
                if(c == 'z'+1)
                    c = 'a';
            }
        }
        
        answer += c;
    }
    
    return answer;
}