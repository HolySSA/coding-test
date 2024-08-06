function solution(brown, yellow) {
    var answer = [];
    
    let sum = brown+yellow;
    for(let i=3; i<=sum; i++){
        if(sum%i === 0){
            let row = sum/i;
            
            if((i-2)*(row-2) === yellow){
                answer.push(row);
                answer.push(i);
                break;
            }
        }
    }
    
    return answer;
}