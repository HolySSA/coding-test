function solution(cap, n, deliveries, pickups) {
    let answer = 0;
    
    let deliveryBox = 0, pickupBox = 0;
    for(let i = n - 1; i >= 0; i--) {
        deliveryBox -= deliveries[i];
        pickupBox -= pickups[i];
        
        let cnt = 0;
        while(deliveryBox < 0 || pickupBox < 0) {
            deliveryBox += cap;
            pickupBox += cap;
            
            cnt++;
        }
        
        // 왕복
        answer += (i + 1) * cnt * 2;
    }
    
    return answer;
}