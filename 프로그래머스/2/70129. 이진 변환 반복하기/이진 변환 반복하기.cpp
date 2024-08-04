#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zero=0, cnt=0;
    while(s.length() > 1){
        string tmp = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0')
                zero++;
            else
                tmp += s[i];
        }
        
        int tmp_size = tmp.length();
        vector<int> binary;
        while(tmp_size > 0){
            binary.push_back(tmp_size%2);
            tmp_size /= 2;
        }
        
        s.clear();
        for(int i=binary.size()-1; i>=0; i--)
            s += to_string(binary[i]);
        
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}