#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), Comp);
    
    int cur = 0;
    for(auto target: targets) {
        if(cur <= target[0]) {
            cur = target[1];
            answer++;
        }
    }
    
    return answer;
}