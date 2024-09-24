function solution(x, y, n) {
    let dp = Array(y+1).fill(1000001);
    
    dp[y] = 0;
    
    for(let i=y; i>x; i--){
        if(dp[i] !== 1000001){
            if(i%3 === 0)
                dp[i/3] = Math.min(dp[i/3], dp[i]+1);
            if(i%2 === 0)
                dp[i/2] = Math.min(dp[i/2], dp[i]+1);
            if(i-n > 0)
                dp[i-n] = Math.min(dp[i-n], dp[i]+1);
        }
    }
    
    if(dp[x] === 1000001)
        dp[x] = -1;
    
    return dp[x];
}