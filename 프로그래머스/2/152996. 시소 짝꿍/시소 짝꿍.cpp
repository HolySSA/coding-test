#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(int a, int b) {
    return a > b;
}

bool Seesaw(int a, int b) {
    if(a == b)
        return true;
    if(a == 2 * b)
        return true;
    if(2 * a == 3 * b)
        return true;
    if(3 * a == 4 * b)
        return true;
    
    return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end(), Comp);
    
    for(int i = 0; i < weights.size() - 1; i++) {
        for(int j = i + 1; j < weights.size(); j++) {
            if(Seesaw(weights[i], weights[j]))
                answer++;
        }
    }
    
    return answer;
}