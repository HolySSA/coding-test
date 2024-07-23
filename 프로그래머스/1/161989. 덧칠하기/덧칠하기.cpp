#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    sort(section.begin(), section.end());
    
    int check = 0;
    for(int i=0; i<section.size(); i++){
        if(section[i] <= check)
            continue;
        
        check = section[i] + m - 1;
        answer++;
    }
    
    return answer;
}