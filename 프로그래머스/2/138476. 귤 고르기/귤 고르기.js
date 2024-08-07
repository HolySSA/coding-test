function solution(k, tangerine) {
    var answer = 0;
    
    const mandarin = {}; 
    tangerine.forEach((a) => {
        mandarin[a] = mandarin[a] ? mandarin[a]+1 : 1;
    });
    
    const cnt = Object.values(mandarin).sort((a, b) => b - a);
    
    for (const t of cnt) {
        if(k <= 0)
            break;
        
        k -= t;
        answer++;
    }
    
    return answer;
}