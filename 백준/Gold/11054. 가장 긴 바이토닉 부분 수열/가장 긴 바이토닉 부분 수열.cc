#include<iostream>
using namespace std;

#define MAX 1001

int dp[MAX];
int b_dp[MAX];
int arr[MAX];

int main(){
    int n; cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    for(int i=n;i>=1;i--){
        b_dp[i]=1;
        for(int j=n;j>i;j--){
            if(arr[i]>arr[j])
                b_dp[i] = max(b_dp[i], b_dp[j]+1);
        }
    }
    
    int result = 0;
    
    for(int i=1;i<=n;i++)
        result = max(result, dp[i]+b_dp[i]-1);
    
    cout<<result;
    
    return 0;
}