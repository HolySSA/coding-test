#include<iostream>
#include<algorithm>
using namespace std;

int dp[3][1001];   // [0][]빨 [1][]초 [2][]파
int arr[3];        // [0]빨 [1]초 [2]파

int main(){
    int n; cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>arr[0]>>arr[1]>>arr[2];
        
        dp[0][i] = min(dp[1][i-1], dp[2][i-1]) + arr[0];
        dp[1][i] = min(dp[0][i-1], dp[2][i-1]) + arr[1];
        dp[2][i] = min(dp[0][i-1], dp[1][i-1]) + arr[2];
    }
    
    cout<<min({dp[0][n], dp[1][n], dp[2][n]});
    
    return 0;
}