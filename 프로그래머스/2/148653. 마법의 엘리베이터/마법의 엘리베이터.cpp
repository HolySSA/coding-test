#include <string>
#include <cstring>
#include <vector>

using namespace std;

int answer = 0;

void Calcul(int num) {
    if(num == 0)
        return;
    
    if(num % 10 > 5 || (num % 10 == 5 && (num % 100) / 10 >= 5)) {
        answer += 10 - (num % 10);
        num += 10;
    }
    else {
        answer += num % 10;
    }
    
    Calcul(num / 10);
}

int solution(int storey) {
    Calcul(storey);
    
    return answer;
}