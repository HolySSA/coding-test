function solution(n, info) {
    let answer = [];
    
    let ryan = new Array(11).fill(0);
    let apeach = [...info];
    
    let scoreDiff = 0;
    
    function lowScore() {
        for(let i = 10; i >= 0; i--) {
            if(ryan[i] > answer[i])
                return true;
            
            if(ryan[i] < answer[i])
                return false;
        }
        
        return false;
    }
    
    function compScore() {
        let ryanScore = 0;
        let apeachScore = 0;
        
        for(let i = 0; i < 11; i++) {
            if(ryan[i] > apeach[i]) {
                ryanScore += 10 - i;
                continue;
            }
            
            if(apeach[i] > 0)
                apeachScore += 10 - i;
        }
        
        let diff = ryanScore - apeachScore;
        if(diff > 0) {
            if(scoreDiff < diff || (scoreDiff === diff && lowScore())) {
                scoreDiff = diff;
                answer = [...ryan];
            }
        }
    }
    
    function shoot(idx, arrows) {
        if(idx === 11 || arrows === 0) {
            ryan[10] += arrows;
            compScore();
            ryan[10] -= arrows;
            
            return;
        }
        
        if(arrows > apeach[idx]) {
            ryan[idx] += apeach[idx] + 1;
            shoot(idx + 1, arrows - (apeach[idx] + 1));
            ryan[idx] -= apeach[idx] + 1;
        }
        
        shoot(idx + 1, arrows);
    }
    
    shoot(0, n);
    
    if(answer.length === 0)
        answer.push(-1);
    
    return answer;
}