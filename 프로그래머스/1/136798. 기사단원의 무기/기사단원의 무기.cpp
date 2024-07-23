#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    vector<int> attack;
    for(int i=1; i<=number; i++){
        // 약수 구하기
        int div = 1; // 자기 자신
        for(int j=1; j<=i/2; j++){
            if(i%j == 0)
                div++;  
        }
        
        div = div>limit ? power : div;
        attack.push_back(div);
    }
    
    for(int i=0; i<attack.size(); i++)
        answer += attack[i];
    
    return answer;
}