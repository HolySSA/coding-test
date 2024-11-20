function solution(n, results) {
    let answer = 0;
    let fight = Array.from(Array(n + 1), () => Array(n + 1).fill(0));
    
    for(let i = 0; i < results.length; i++) {
        fight[results[i][0]][results[i][1]] = 1;
    }
    
    // 플로이드-와샬 알고리즘
    for (let k = 1; k <= n; k++) { // 중간
        for (let i = 1; i <= n; i++) { // 시작
            for (let j = 1; j <= n; j++) { // 끝
                if (fight[i][k] === 1 && fight[k][j] === 1) {
                    fight[i][j] = 1;
                }
            }
        }
    }
    
    for(let i = 1; i <= n; i++) {
        let tmp = 0;
        for(let j = 1; j <= n; j++) {
            tmp += fight[i][j];
            tmp += fight[j][i];
        }
        
        if(tmp == n - 1)
            answer++;
    }
    
    return answer;
}