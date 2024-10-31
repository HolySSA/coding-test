#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int substitute(ll idx, int level) {
    if(level == 0)
        return 1;
    
    ll size = pow(5, level);
    // 11 0 11 <<< 가운데 부분을 도출 (항상 가운데는 0)
    if(size / 5 * 2 <= idx && idx < size / 5 * 3)
        return 0;
    
    return substitute(idx % (size / 5), level - 1);
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    for(ll i = l; i <= r; i++) {
        answer += substitute(i - 1, n);
    }
    
    return answer;
}