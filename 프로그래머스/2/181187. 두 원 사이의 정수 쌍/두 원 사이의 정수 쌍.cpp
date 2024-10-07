#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long r1_pow = (long long)pow(r1, 2);
    long long r2_pow = (long long)pow(r2, 2);
    for(int i = 1; i <= r2; i++) {
        long long i_pow = (long long)pow(i, 2);
        
        int minY = ceil(sqrt(r1_pow - i_pow));
        int maxY = floor(sqrt(r2_pow - i_pow));

        if (r1 < i)
            minY = 0;

        answer += maxY - minY + 1;
    }
    
    answer *= 4;
    
    return answer;
}