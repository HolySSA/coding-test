function solution(n, m) {
    var answer = [];
    
    let gcd = 1;
    
    let maxNum = Math.max(n, m);
    for(let i=1; i<=maxNum; i++){
        if(n%i === 0 && m%i === 0)
            gcd = i;
    }
    
    let cm = n*m/gcd;
    
    answer.push(gcd);
    answer.push(cm);
    
    return answer;
}