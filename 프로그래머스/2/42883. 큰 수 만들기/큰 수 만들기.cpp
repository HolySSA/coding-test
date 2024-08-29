#include <string>
#include <vector>

using namespace std;

// dfs 돌렸는데 시간초과나서 그리디
string solution(string number, int k) {
    string answer = "";
    
    for(int i=0; i<number.length(); i++){
        while(k>0 && answer != "" && number[i] > answer.back()){
            answer.pop_back();
            k--;
        }
        
        if(answer.length() < number.length()-k)
            answer += number[i];
    }
    
    return answer;
}