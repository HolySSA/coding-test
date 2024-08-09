function solution(citations) {
    var answer = 0;
    
    citations.sort((a, b) => b-a);
    
    citations.forEach((a, idx) => {
        if(a >= idx+1)
            answer++;
        else
            return;
    })
    
    return answer;
}