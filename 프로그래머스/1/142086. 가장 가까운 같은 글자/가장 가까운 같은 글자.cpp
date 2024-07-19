#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    // 처음은 무조건 -1
    answer.push_back(-1);
    for(int i=1; i<s.length(); i++){
        int tmp = 10001;
        for(int j=0; j<i; j++){
            if(s[i] == s[j])
                tmp = i-j;
            
            if(j == i-1){
                if(tmp != 10001)
                    answer.push_back(tmp);
                else
                    answer.push_back(-1);
            }
        }
    }
    
    return answer;
}