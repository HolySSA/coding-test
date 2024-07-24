#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> talk = { "aya", "ye", "woo", "ma" };

    for(int i=0; i<babbling.size(); i++){
        int check = 0;
        for(int j=0; j<babbling[i].length(); j++){
            if(babbling[i].substr(j, 3) == talk[0] && check != 1){
                check = 1;
                j+=2;
            }
            else if(babbling[i].substr(j, 2) == talk[1] && check != 2){
                check = 2;
                j+=1;
            }
            else if(babbling[i].substr(j, 3) == talk[2] && check != 3){
                check = 3;
                j+=2;
            }
            else if(babbling[i].substr(j, 2) == talk[3] && check != 4){
                check = 4;
                j+=1;
            }
            else{
                check = 0;
                break;
            }
        }
        
        if(check != 0)
            answer++;
    }
    
    return answer;
}