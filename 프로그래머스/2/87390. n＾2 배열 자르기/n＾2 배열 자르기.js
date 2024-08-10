function solution(n, left, right) {
    var answer = [];
    
    for(let i=left; i<=right; i++){
        let div = Math.floor(i/n);
        let mod = i%n;
        
        answer.push(Math.max(div, mod)+1);
    }
    
    return answer;
}