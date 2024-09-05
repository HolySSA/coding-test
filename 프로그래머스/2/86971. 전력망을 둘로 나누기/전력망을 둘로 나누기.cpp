#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int BFS(int cnt, int startNode, int cutNode, vector<vector<int>> lines, int n) {
    queue<int> q;
    vector<bool> visited(n+1);
    
    q.push(startNode);
    visited[startNode] = true;
    visited[cutNode] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < lines[cur].size(); i++) {
            int next = lines[cur][i];
                                                 
            if(visited[next])
                continue;
            
            cnt++;
            q.push(next);
            visited[next] = true;
        }
    }
    
    cout<<cnt<<' ';
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    vector<vector<int>> lines(n+1, vector<int>());
    
    for(auto wire: wires) {
        lines[wire[0]].push_back(wire[1]);
        lines[wire[1]].push_back(wire[0]);
    }
    
    for(auto wire: wires) {
        int cnt = BFS(1, wire[0], wire[1], lines, n);
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    
    return answer;
}