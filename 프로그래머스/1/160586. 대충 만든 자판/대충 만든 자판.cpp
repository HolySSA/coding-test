#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i=0; i<targets.size(); i++){
        int total = 0;
        for(int j=0; j<targets[i].length(); j++){
            int min_check = 101;
            
            for(int k = 0; k < keymap.size(); k++){
                int pos = keymap[k].find(targets[i][j]);
                if(pos != string::npos)
                    min_check = min(min_check, pos + 1);          
            }
            
            if(min_check == 101) {
                total = -1;
                break;
            }
            
            total += min_check;
        }
        
        answer.push_back(total);
    }
    
    return answer;
}