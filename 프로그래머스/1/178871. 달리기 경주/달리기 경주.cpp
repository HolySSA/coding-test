#include <string>
#include <vector>
#include <map>

using namespace std;

// 2중 for문으로 풀면 시간초과
vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> rank;
    
    for(int i=0; i<players.size(); i++){
        rank[players[i]] = i;
    }
    
    for(int i=0; i<callings.size(); i++){
        int cur_rank = rank[callings[i]];
        
        rank[players[cur_rank]]--;
        rank[players[cur_rank-1]]++;
        
        swap(players[cur_rank], players[cur_rank-1]);
    }
    
    return players;
}