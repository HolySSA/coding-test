function solution(board) {
    let answer = 2e9;
    
    let start = [];
    let visited = new Array(board.length).fill(false).map(() => new Array(board[0].length));
    
    let dr = [1, -1, 0, 0];
    let dc = [0, 0, 1, -1];
    
    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[i].length; j++) {
            if(board[i][j] === 'R')
                start = [i, j];
        }
    }
    
    function BFS() {
        let queue = [];
        
        queue.push([[start[0], start[1]], 0]);
        visited[start[0]][start[1]] = true;
        
        while(queue.length !== 0) {
            let cur = queue[0][0];
            let cnt = queue[0][1];
            
            queue.shift();
            
            if(board[cur[0]][cur[1]] === 'G') {
                answer = Math.min(answer, cnt);
                continue;
            }
            
            for(let i = 0; i < 4; i++) {
                let nr = cur[0] + dr[i];
                let nc = cur[1] + dc[i];
                
                if(nr < 0 || nc < 0 || nr >= board.length || nc >= board[nr].length)
                    continue;
                if(board[nr][nc] === 'D')
                    continue;
                
                while(1) {
                    nr += dr[i];
                    nc += dc[i];
                    
                    if(nr < 0 || nc < 0 || nr >= board.length || nc >= board[nr].length) {
                        nr -= dr[i];
                        nc -= dc[i];
                        break;
                    }
                    if(board[nr][nc] === 'D') {
                        nr -= dr[i];
                        nc -= dc[i];
                        break;
                    }
                }
                
                if(visited[nr][nc])
                    continue;
                
                queue.push([[nr, nc], cnt + 1]);
                visited[nr][nc] = true;
            }
        }
    }
    
    BFS();
    
    if(answer === 2e9)
        return -1
    
    return answer;
}