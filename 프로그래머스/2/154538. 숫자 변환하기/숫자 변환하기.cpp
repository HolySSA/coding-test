#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 1000001

using namespace std;

int dp[MAX];

int solution(int x, int y, int n) {
    fill(dp, dp+y+1, MAX);

    dp[y] = 0;
    
    for(int i=y; i>x; i--){
        if(dp[i] != MAX){
            if(i%3 == 0)
                dp[i/3] = min(dp[i/3], dp[i]+1);
            if(i%2 == 0)
                dp[i/2] = min(dp[i/2], dp[i]+1);
            if(i-n > 0)
                dp[i-n] = min(dp[i-n], dp[i]+1);
        }
    }
    
    if(dp[x] == MAX)
        dp[x] = -1;
    
    return dp[x];
}