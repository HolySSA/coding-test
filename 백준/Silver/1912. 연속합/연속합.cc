#include<iostream>
using namespace std;

#define MAX 100001

int dp[MAX];
int arr[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    int sum = -1000;
    dp[0]=0;
    
    for(int i=1; i<=n; ++i){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        sum = max(sum, dp[i]);
    }
    
    cout<<sum;    

    return 0;
}