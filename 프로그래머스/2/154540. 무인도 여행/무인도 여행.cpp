#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> answer;
int sum = 0;

bool visited[100][100];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

void BFS(vector<string> &maps) {
    for(int r = 0; r < maps.size(); r++) {
        for(int c = 0; c < maps[r].length(); c++) {
            if(maps[r][c] != 'X' && !visited[r][c]) {
                queue<pair<int, int>> q;
                
                visited[r][c] = true;
                q.push(make_pair(r, c));
                sum += maps[r][c] - '0';
                
                while(!q.empty()) {
                    int cr = q.front().first;
                    int cc = q.front().second;
                    q.pop();
                    
                    for(int i = 0; i < 4; i++){
                        int nr = cr + dr[i];
                        int nc = cc + dc[i];
                            
                        if(nr < 0 || nc < 0 || nr >= maps.size() || nc >= maps[r].length())
                            continue;
                        if(visited[nr][nc])
                            continue;
                        if(maps[nr][nc] == 'X')
                            continue;
                        
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                        sum += maps[nr][nc] - '0';
                    }
                }
                
                answer.push_back(sum);
                sum = 0;
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    BFS(maps);

    if(answer.empty())
        answer.push_back(-1);
    
    sort(answer.begin(), answer.end());

    return answer;
}