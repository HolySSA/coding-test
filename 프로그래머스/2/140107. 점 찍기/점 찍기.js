function solution(k, d) {
    let answer = 0;
    
    const DistanceY = (d, x) => {
        return Math.sqrt(Math.pow(d, 2) - Math.pow(x, 2));
    }
    
    let i = 0;
    while(i * k <= d) {
        let maxY = DistanceY(d, i * k);
        
        answer += Math.floor(maxY / k) + 1;
        
        i++;
    }
    
    return answer;
}