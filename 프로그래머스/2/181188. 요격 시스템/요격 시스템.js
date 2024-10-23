function solution(targets) {
    let answer = 0;
    
    targets.sort((a, b) => a[1] - b[1]);
    
    let cur = 0;
    for(const target of targets) {
        if(cur <= target[0]) {
            cur = target[1];
            answer++;
        }
    }
    
    return answer;
}