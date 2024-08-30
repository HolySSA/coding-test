function solution(n) {
    let answer = [];
    let snail = Array.from(Array(n+1), () => Array(n+1).fill(null))
    
    let val=1, y=1, x=1;
    for(let i=1; i<=n; i++){
        if(i%3 === 1){
            for(let j=i; j<=n; j++)
                snail[y++][x] = val++;
            
            // 'ㅡ' 수행해야하니까 y위, x오른쪽으로 (계산할 인덱스로)
            y--;
            x++;
        }
        else if(i%3 === 2){
            for(let j=i; j<=n; j++)
                snail[y][x++] = val++;
            
            // '\' 수행해야하니까 y위, x왼쪽2칸으로 (계산할 인덱스로)
            y--;
            x -= 2;
        }
        else if(i%3 === 0){
            for(let j=i; j<=n; j++)
                snail[y--][x--] = val++;
            
            // '/' 수행해야하니까 y아래(2칸), x오른쪽으로 (계산할 인덱스로)
            y += 2;
            x++;
        }
    }
    
    for(let i=1; i<=n; i++){
        for(let j=1; j<=i; j++)
            answer.push(snail[i][j]);
    }
    
    return answer;
}