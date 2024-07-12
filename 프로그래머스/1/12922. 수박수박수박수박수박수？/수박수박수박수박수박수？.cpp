#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0){
        if(answer.length()%2 == 0)
            answer += "수";
        else
            answer += "박";
        
        n--;
    }
    
    return answer;
}