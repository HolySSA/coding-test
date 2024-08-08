#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int cnt=0; cnt<s.length(); cnt++){
        stack<char> st;

        if(s[0] == ')' || s[0] == ']' || s[0] == '}'){
            s += s[0];
            s.erase(0, 1);
            continue;
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                if(st.top() == '(' && s[i] == ')')
                    st.pop();
                else if(st.top() == '[' && s[i] == ']')
                    st.pop();
                else if(st.top() == '{' && s[i] == '}')
                    st.pop();
                else{
                    st.push(s[i]);
                    break;
                }
            }
        }

        if(st.empty())
            answer++;
        
        s += s[0];
        s.erase(0, 1);
    }
    
    return answer;
}