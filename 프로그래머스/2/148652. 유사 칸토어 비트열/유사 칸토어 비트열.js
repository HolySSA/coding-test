function solution(n, l, r) {
    let answer = 0;
    
    function findZero(num){
        if (num < 5 && num != 2)
            return true;
        if ((num - 2) % 5 === 0)
            return false;
        
        return findZero(Math.floor(num / 5));
    }

    
    for(let i = l; i <= r; i++) {
        if(findZero(i - 1))
            answer++;
    }
    
    return answer;
}