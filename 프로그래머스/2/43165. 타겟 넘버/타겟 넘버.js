function solution(numbers, target) {
    let answer = 0;
    
    function DFS(idx, sum){
        if(idx === numbers.length){
            if(sum === target)
                answer++;
            
            return;
        }
        
        DFS(idx+1, sum+numbers[idx]);
        DFS(idx+1, sum-numbers[idx]);
    }
    
    DFS(0, 0);
    
    return answer;
}