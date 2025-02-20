#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    string str; cin>>str;
    string suffix[str.length()];

    for(int i=0;i<str.length();i++){
        suffix[i] = str.substr(i, str.length());
    }
    
    sort(suffix, suffix+str.length());
    
    for(int i=0;i<str.length();i++)
        cout<<suffix[i]<<'\n';
    
    return 0;
}