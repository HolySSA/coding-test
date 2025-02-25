#include<iostream>
using namespace std;

#define MOD 1000000000

int dp[201][201];    // [숫자][횟수]

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin>>n>>k;
    
    for (int i=0;i<=k;i++)
        dp[1][i] = i;
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    
    cout<<dp[n][k];
    
    return 0;
}