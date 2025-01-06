#include<iostream>
using namespace std;

#define MAX 20000000

int n;
int S[20];
bool visited[MAX];

void Program(int idx, int sum){
    visited[sum] = true;
    
    if(idx == n)
        return;
    
    Program(idx+1, sum);
    Program(idx+1, sum+S[idx]);
}

int main(){
    cin>>n;
    
    for(int i=0; i<n; i++)
        cin>>S[i];

    Program(0, 0);
    
    int cnt = 1;
    while(visited[cnt])
    	cnt++;
	
    cout<<cnt;
}