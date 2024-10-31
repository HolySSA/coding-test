function solution(r1, r2) {
    let answer = 0;
    
    const r1_pow = Math.pow(r1, 2);
    const r2_pow = Math.pow(r2, 2);
    
    for(let i = 1; i <= r2; i++) {
        let i_pow = Math.pow(i, 2);
        
        let minY = Math.ceil(Math.sqrt(r1_pow - i_pow));
        let maxY = Math.floor(Math.sqrt(r2_pow - i_pow));
        
        if(r1 < i)
            minY = 0;
        
        answer += maxY - minY + 1;
    }
    
    answer *= 4;
    
    return answer;
}