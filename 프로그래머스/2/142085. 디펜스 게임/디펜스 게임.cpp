#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    priority_queue<int, vector<int>, less<int>> pq;
    
    for(int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);
        n -= enemy[i];
        
        if(n < 0) {
            if(k == 0) {
                answer = i;
                break;
            }
            
            // 무적권
            while(!pq.empty() && k > 0 && n < 0){
                k--;
                n += pq.top();
                pq.pop();
            }
        }
    }
    
    return answer;
}