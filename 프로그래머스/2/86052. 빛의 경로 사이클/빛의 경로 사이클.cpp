#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<string> board;
bool visited[501][501][4];
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

int shoot(int r, int c, int dir) {
    int cnt = 0;
    
    while(!visited[r][c][dir]) {
        visited[r][c][dir] = true;
        cnt++;
        
        if (board[r][c] == 'L')
            dir = (dir + 1) % 4;
        else if (board[r][c] == 'R')
            dir = (dir + 3) % 4;
            
        r = (r + dr[dir] + n) % n;
        c = (c + dc[dir] + m) % m;
    }
    
    return cnt;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    n = grid.size();
    m = grid[0].length();
    board = grid;
    
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            for(int dir = 0; dir < 4; dir++) {
                if (!visited[r][c][dir]) {
                    int result = shoot(r, c, dir);
                    answer.push_back(result);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}