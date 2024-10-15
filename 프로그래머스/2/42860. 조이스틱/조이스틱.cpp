#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int cnt = 0;
    int move = name.length() - 1;
    for(int i = 0; i < name.length(); i++) {
        // 위아래
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);        
        
        int idx = i + 1;
        while(idx < name.length()) {
            if(name[idx] == 'A')
                idx++;
            else
                break;
        }
        
        cnt = name.length() - 1 - idx + 1;
        move = min(move, i + cnt + min(i, cnt));         
    }
    
    return answer + move;
}