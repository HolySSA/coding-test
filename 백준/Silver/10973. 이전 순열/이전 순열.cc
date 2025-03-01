#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 10000

bool des(int a, int b){
    return a>b;
}

int main(){
    int n; cin>>n;
    int num[MAX];
    
    for(int i=0;i<n;i++)
        cin>>num[i];
    
    if(prev_permutation(num, num+n)){
        for(int i=0;i<n;i++)
            cout<<num[i]<<' ';
        cout<<'\n';
    }
    else
        cout<<-1;
    
    return 0;
}