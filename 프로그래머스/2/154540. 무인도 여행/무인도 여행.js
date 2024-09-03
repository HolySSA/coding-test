function solution(maps) {
    let answer = [];
    
    let visited = Array.from({ length: maps.length }, () => Array(maps[0].length).fill(false));
    let dr = [ 0, 0, 1, -1 ];
    let dc = [ 1, -1, 0, 0 ];
    
    let sum = 0;
    const BFS = (r, c) => {
        let queue = [[r, c]];
        visited[r][c] = true;
        sum += parseInt(maps[r][c]);
        
        while(queue.length > 0) {
            let [cr, cc] = queue[0];
            queue.shift();
            
            for(let i = 0; i < 4; i++) {
                let [nr, nc] = [cr + dr[i], cc + dc[i]];
                
                if(nr < 0 || nc < 0 || nr >= maps.length || nc >= maps[r].length)
                    continue;
                if(visited[nr][nc])
                    continue;
                if(maps[nr][nc] === 'X')
                    continue;
                
                queue.push([nr, nc]);
                visited[nr][nc] = true;
                sum += parseInt(maps[nr][nc]);
            }
        }
        
        answer.push(sum);
        sum = 0;
    }
    
    for(let r = 0; r < maps.length; r++) {
        for(let c = 0; c < maps[r].length; c++) {
            if(maps[r][c] !== 'X' && !visited[r][c])
                BFS(r, c);
        }
    }
    
    if(!answer.length)
        answer.push(-1);
    
    answer.sort((a, b) => a - b);
    
    return answer;
}