#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // 배달 박스, 수거 박스
    long long deliverBox = 0;
    long long pickupBox = 0;
    
    for(int i = n - 1; i >= 0; i--) {
        deliverBox -= deliveries[i];
        pickupBox -= pickups[i];
        
        // 횟수
        int cnt = 0;
        while(deliverBox < 0 || pickupBox < 0) {
            // 배달, 수거 완료될 때까지 횟수 증가
            deliverBox += cap;
            pickupBox += cap;
            
            cnt++;
        }
        
        // 왕복
        answer += (i + 1) * cnt * 2;
    }
    
    return answer;
}