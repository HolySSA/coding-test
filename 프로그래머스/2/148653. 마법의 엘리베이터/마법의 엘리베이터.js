function solution(storey) {
    let answer = 0;
    
    function Move(storey) {
        if(storey === 0) {
            return;
        }

        if(Math.floor(storey % 10) > 5 || (Math.floor(storey % 10) === 5) && Math.floor(storey % 100) / 10 >= 5) {
            answer += 10 - Math.floor(storey % 10);
            storey += 10;
        }
        else {
            answer += Math.floor(storey % 10);
        }
        
        Move(Math.floor(storey / 10));
    }
    
    Move(storey);
    
    return answer;
}