#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

bool leverCheck = false;
int visited[100][100] = { 0, };
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int BFS(int cnt, pair<int, int> start, vector<string> &maps) {
    queue<pair<int, int>> q;
    
    q.push(start);
    visited[start.first][start.second] = 0;
    
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        
        if(!leverCheck && maps[cr][cc] == 'L') {
            leverCheck = true;
            int leverCnt = visited[cr][cc];
            memset(visited, 0, sizeof(visited));
            return cnt + leverCnt;
        }
        
        if(leverCheck && maps[cr][cc] == 'E') {
            return cnt + visited[cr][cc];
        }
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nr >= maps.size() || nc < 0 || nc >= maps[0].length())
                continue;
            if(visited[nr][nc])
                continue;
            if(maps[nr][nc] == 'X')
                continue;
            
            q.push(make_pair(nr, nc));
            visited[nr][nc] = visited[cr][cc] + 1;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    pair<int, int> start;
    pair<int, int> lever;
    
    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].length(); j++) {
            if(maps[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
            if(maps[i][j] == 'L') {
                lever.first = i;
                lever.second = j;
            }
        }
    }
    
    int leverCnt = BFS(0, start, maps);
    cout<<"레버: "<<leverCnt<<'\n';
    answer = BFS(leverCnt, lever, maps); 
    cout<<"엔드: "<< answer;
    return answer;
}