#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool Comp(int a, int b){
    return a>b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> mandarin;
    vector<int> cnt;
    
    for(int i=0; i<tangerine.size(); i++)
        mandarin[tangerine[i]]++;
    
    for(auto c : mandarin)
        cnt.push_back(c.second);
    
    sort(cnt.begin(), cnt.end(), Comp);
    
    for(int i=0; i<cnt.size(); i++){
        if(k <= 0)
            break;
        
        k -= cnt[i];
        answer++;
    }
    
    return answer;
}