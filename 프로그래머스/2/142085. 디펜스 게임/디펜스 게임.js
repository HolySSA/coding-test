function solution(n, k, enemy) {
    let answer = enemy.length;
    
    let low = 0, high = enemy.length;
    while(low <= high) {
        let mid = Math.floor((low + high) / 2);
        let curEnemy = enemy.slice(0, mid).sort((a, b) => b - a);
        let curK = k;
        
        const curSum = curEnemy.reduce((acc, val) => {
            if (curK > 0) {
                curK--;
                return acc;
            }
            else
                return acc + val
        }, 0);
        
        if(n - curSum >= 0 && curK >= 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    answer = low - 1;
    
    return answer;
}