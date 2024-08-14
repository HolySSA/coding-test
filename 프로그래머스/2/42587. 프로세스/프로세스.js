function solution(priorities, location) {
    var answer = 0;
    
    let check = priorities.map((a, idx) => {
        if(idx === location)
            return true;
        return false;
    });
    
    let max = Math.max.apply(null, priorities);
    while(1){
        if(priorities[0] < max){
            priorities.push(priorities[0]);
            priorities.shift();
            check.push(check[0]);
            check.shift();
        }
        else{
            if(check[0] === true){
                answer++;
                break;
            }  
            
            priorities.shift();
            check.shift();
            answer++;
            
            max = Math.max.apply(null, priorities);
        }
            
    }
    
    return answer;
}