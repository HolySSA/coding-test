#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector<string> v,vt;
    int n, m;
    cin >> n >> m;
    
    string s;
    
    for(int i=0; i<n; i++) {
        cin>>s;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<m; i++) {
        cin>>s;
        if(binary_search(v.begin(), v.end(), s)) { // 찾는 s가 있으면 1(true) 없으면 0(false)
            vt.push_back(s);
        }
    }
    
    sort(vt.begin(), vt.end());
    
    cout << vt.size() << "\n";
    
    for (auto o : vt) {
        cout << o << "\n";
    }
    
    return 0;
}