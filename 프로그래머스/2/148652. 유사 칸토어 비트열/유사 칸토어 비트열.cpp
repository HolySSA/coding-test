#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

bool findZero(ll num) {
    if(num < 5 && num != 2)
        return true;
    if((num - 2) % 5 == 0)
        return false;
    
    return findZero(floor(num / 5));
}

int solution(int n, ll l, ll r) {
    int answer = 0;
    
    for(ll i = l; i <= r; i++) {
        if(findZero(i - 1))
            answer++;
    }
    
    return answer;
}