#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = bridge_length;
    
    queue<int> bridge;
    int sum=0, idx=0;
    while(1){
        if(idx == truck_weights.size())
            break; 
        
        if(bridge.size() == bridge_length){
            sum -= bridge.front();
            bridge.pop();
        }
        
        if(sum+truck_weights[idx] <= weight){
            sum += truck_weights[idx];
            bridge.push(truck_weights[idx++]);
        }
        else
            bridge.push(0); // 시간 계산을 위해서 일부러 0을 push
        
        answer++;
    }
    
    return answer;
}