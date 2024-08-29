#include <string>
#include <vector>

using namespace std;

// dfs 돌렸는데 시간초과나서 그리디
string solution(string number, int k) {
    string answer = "";
    
    int idx = -1;
    // 하나씩 뽑는 게 아니라 순서대로라서 해당 범위로 루프
    for(int i=0; i<number.length()-k; i++){
        char maxNum = ' ';
        
        for(int j=idx+1; j<=i+k; j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                idx = j;
            }
        }
        
        answer += maxNum;
    }
    
    return answer;
}