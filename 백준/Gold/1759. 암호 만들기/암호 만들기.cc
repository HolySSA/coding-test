#include<iostream>
#include<algorithm>
using namespace std;

int l, c;
char input[15], password[15];
bool visited[15];

void Password(int cnt, int idx){
    if(cnt == l){
        int vowel=0, consonant=0;
        for(int i=0;i<l;i++){
            if(password[i] == 'a' || password[i] == 'i' || password[i] == 'u' ||
               password[i] == 'e' || password[i] == 'o')
                vowel++;
            else
                consonant++;
        }
        
        if(vowel>=1 && consonant>=2){
            for(int i=0;i<l;i++)
                cout<<password[i];
            cout<<'\n';
        }
        return;
    }
    
    for(int i=idx;i<c;i++){
        if(!visited[i]){
            visited[i] = true;
            password[cnt] = input[i];
            Password(cnt+1, i);
            visited[i] = false;
        }
    }
}

int main(){
    cin>>l>>c;
    
    for(int i=0;i<c;i++)
        cin>>input[i];
    
    sort(input, input+c);
    
    Password(0, 0);
    
    return 0;
}