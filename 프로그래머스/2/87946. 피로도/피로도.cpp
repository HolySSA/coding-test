#include <string>
#include <vector>

using namespace std;

int answer = -1;
bool visited[8];

void DFS(int cnt, int k, vector<vector<int>> &dungeons) {
    if(cnt > answer)
        answer = cnt;
    
    for(int i=0; i<dungeons.size(); i++){
        if(visited[i])
            continue;
        if(dungeons[i][0] > k)
            continue;
        
        visited[i] = true;
        DFS(cnt+1, k-dungeons[i][1], dungeons);
        visited[i] = false;
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    DFS(0, k, dungeons);
    
    return answer;
}