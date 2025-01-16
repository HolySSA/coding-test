#include<iostream>
#include<map>
using namespace std;

map<int, bool> maps;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n+m;i++){
        int num;
        cin>>num;
        
        if(maps[num] == true)
            maps.erase(num);
        else
            maps[num] = true;
    }
    
    cout<<maps.size();
    
    return 0;
}