#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 2e9;
pair<int, int> start;
vector<vector<int>> visited;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void BFS(vector<string> &board) {
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{start.first, start.second}, 0});
    visited[start.first][start.second] = true;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(board[cur.first][cur.second] == 'G') {
            answer = min(answer, cnt);
        }
        
        for(int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            
            if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board[nr].length())
                continue;  
            if(board[nr][nc] == 'D')
                continue;
            
            while (true) {
                nr += dr[i];
                nc += dc[i];
                
                if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board[nr].length()) {
                    nr -= dr[i];
                    nc -= dc[i];
                    break;
                }
                if(board[nr][nc] == 'D') {
                    nr -= dr[i];
                    nc -= dc[i];
                    break;
                }
            }
           
            if(visited[nr][nc])
                continue;
            
            q.push({make_pair(nr, nc), cnt + 1});
            visited[nr][nc] = true;
        }
    }
}

int solution(vector<string> board) {
    visited.resize(board.size(), vector<int>(board[0].length(), false));
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].length(); j++) {
            if(board[i][j] == 'R')
                start = make_pair(i, j);
        }
    }
    
    BFS(board);
    
    if(answer == 2e9)
        return -1;
    
    return answer;
}