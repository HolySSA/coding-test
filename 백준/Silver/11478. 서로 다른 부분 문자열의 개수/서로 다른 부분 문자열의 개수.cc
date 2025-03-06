#include <iostream>
#include <map>
using namespace std;
 
int main() {
    string s;
    cin>>s;
 
    map<string, bool> maps;
 
    string str = "";
    for(int i=0; i<s.size(); i++) {
        for (int j=i; j <s.size(); j++) {
            str += s[j];
            maps.insert(make_pair(str, true)); // map은 중복불가
        }
        str = "";
    }
 
    cout << maps.size();
}