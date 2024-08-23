function solution(bridge_length, weight, truck_weights) {
    var answer = bridge_length;
    
    let bridge = [];
    let sum=0, idx=0;
    
    while(1){
        if(idx === truck_weights.length)
            break;
        
        if(bridge.length === bridge_length){
            sum -= bridge[0];
            bridge.shift();
        }
        
        if(sum+truck_weights[idx] <= weight){
            sum += truck_weights[idx];
            bridge.push(truck_weights[idx++]);
        }
        else
            bridge.push(0);
        
        answer++;
    }
    
    return answer;
}