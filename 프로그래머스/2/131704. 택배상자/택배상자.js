function solution(order) {
    let answer = 0;
    
    let sub = [];
    for(let i=1; i<=order.length; i++){
        sub.push(i);
        
        while(sub.length !== 0 && sub[sub.length-1] === order[answer]){
            answer++;
            sub.pop();
        }
    }
    
    return answer;
}