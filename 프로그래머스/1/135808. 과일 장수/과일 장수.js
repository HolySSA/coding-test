function solution(k, m, score) {
    var answer = 0;
    
    score.sort((a, b) => a-b);
    
    while(score.length >= m){
        let box = score.splice(score.length - m, m);
        
        answer += box[0] * m;
    }
    
    return answer;
}