#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool visited[501][501][4];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int refraction(char node, int dir) {
    if (node == 'L') {
        if (dir == 0) return 3;
        if (dir == 1) return 2;
        if (dir == 2) return 0;
        if (dir == 3) return 1;
    } else if (node == 'R') {
        if (dir == 0) return 2;
        if (dir == 1) return 3;
        if (dir == 2) return 1;
        if (dir == 3) return 0;
    }
}

int shoot(int r, int c, int dir, int length, vector<string> &grid) {
    if (visited[r][c][dir])
        return length;
 
    visited[r][c][dir] = true;
 
    int nr = r;
    int nc = c;
    int ndir = dir;
 
    if (grid[r][c] != 'S')
        ndir = refraction(grid[r][c], dir);
    
    nr = r + dr[ndir];
    nc = c + dc[ndir];
    
    if (nr < 0)
        nr = n - 1;
    if (nc < 0)
        nc = m - 1;
    
    if (nr == n)
        nr = 0;
    if (nc == m)
        nc = 0;
 
    return shoot(nr, nc, ndir, length + 1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    n = grid.size();
    m = grid[0].length();
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            for (int d = 0; d < 4; d++) {
                int result = shoot(r, c, d, 0, grid);
                
                if (result != 0)
                    answer.push_back(result);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}