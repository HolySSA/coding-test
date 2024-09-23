function solution(n) {
    let answer = [];
    
    function hanoi(n, from, by, to) {
        let tmp = [];
        
        if(n === 1) {
            tmp.push(from);
            tmp.push(to);      
            answer.push(tmp);
            return;
        }
        
        hanoi(n - 1, from, to, by);
        
        tmp.push(from);
        tmp.push(to);
        answer.push(tmp);
        
        hanoi(n - 1, by, from, to);
    }
    
    hanoi(n, 1, 2, 3);
    
    return answer;
}