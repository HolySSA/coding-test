#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int answer = 1;
vector<vector<pair<int, int>>> info;
vector<int> accumTime;

void BFS(int K) {
    queue<pair<int, int>> q;
   
    q.push({1, 0}); // 1번 마을, 시간 0
    
    while(!q.empty()) {
        int curNode = q.front().first;
        int curTime = q.front().second;
        q.pop();
        
        if(accumTime[curNode] != 0 && accumTime[curNode] < curTime)
            continue;
        if(curTime > K)
            continue;
        
        accumTime[curNode] = curTime;
        
        for(auto next : info[curNode]) {
            if(next.first != 1)
                q.push({next.first, curTime + next.second}); // 다음 노드, 걸린 시간
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    info.resize(N + 1, vector<pair<int, int>>());
    accumTime.resize(N + 1, 0);
    
    for(auto r: road) {
       info[r[0]].push_back(make_pair(r[1], r[2]));
       info[r[1]].push_back(make_pair(r[0], r[2])); 
    }
    
    BFS(K);
    
    for(auto cnt : accumTime) {
        if(cnt)
            answer++;
    }
    
    return answer;
}