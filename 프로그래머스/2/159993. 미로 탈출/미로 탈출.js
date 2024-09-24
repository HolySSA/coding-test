function solution(maps) {
    let answer = 0;
    
    let start = [ 0, 0 ];
    let lever = [ 0, 0 ];
    for(let i = 0; i < maps.length; i++) {
        for(let j = 0; j <maps[i].length; j++) {
            if(maps[i][j] === 'S')
                start[0] = i, start[1] = j;
            if(maps[i][j] === 'L')
                lever[0] = i, lever[1] = j; 
        }
    }
    
    let visited = new Array(maps.length).fill(0).map(() => new Array(maps[0].length));
    let dr = [ 1, -1, 0, 0 ];
    let dc = [ 0, 0, 1, -1 ];
    let leverCheck = false;
    function BFS(cnt, startPoint) {
        let queue = [];
        
        queue.push([startPoint[0], startPoint[1]]);
        visited[startPoint[0]][startPoint[1]] = 0;
        
        while(queue.length !== 0) {
            let cr = queue[0][0];
            let cc = queue[0][1];
            
            queue.shift();
            
            if(!leverCheck && maps[cr][cc] === 'L') {
                leverCheck = true;
                let leverCnt = cnt + visited[cr][cc];
                visited = Array.from(new Array(maps.length), () => new Array(maps[0].length).fill(0));
                return cnt + leverCnt;
            }
            
            if(leverCheck && maps[cr][cc] === 'E') {
                return cnt + visited[cr][cc];
            }
            
            for(let i = 0; i < 4; i++) {
                let nr = cr + dr[i];
                let nc = cc + dc[i];
                
                if(nr < 0 || nc < 0 || nr >= maps.length || nc >= maps[0].length)
                    continue;
                if(visited[nr][nc])
                    continue;
                if(maps[nr][nc] === 'X')
                    continue;
                
                queue.push([nr, nc]);
                visited[nr][nc] = visited[cr][cc] + 1;
            }
        }
        
        return -1;
    }
    
    let leverCnt = BFS(0, start);
    answer = BFS(leverCnt, lever);
    
    if(answer < 0)
        return -1;
    
    return answer;
}