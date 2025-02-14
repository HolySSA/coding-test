#include<iostream>
#include<map>
#include<string>
using namespace std;

map<int, string> monster;
map<string, int> poket;

int main(){
    cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        string str; cin>>str;
        poket[str] = i;
        monster[i] = str;
    }
    
    while(m--){
        string str; cin>>str;
        
        if(str[0] < 'A'){
            cout<<monster[stoi(str)]<<'\n';
            continue;
        }
         
        cout<<poket[str]<<'\n';
    }
    
    return 0;
}