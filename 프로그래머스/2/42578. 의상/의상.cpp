#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> comb;
    
    // 종류별 갯수
    for(int i=0; i<clothes.size(); i++)
        comb[clothes[i][1]]++;
    
    for(auto c : comb)
        answer *= c.second+1;
    
    return --answer;
}