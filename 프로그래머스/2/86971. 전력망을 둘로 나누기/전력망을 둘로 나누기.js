function solution(n, wires) {
    let answer = n + 1;
    
    let lines = new Array(n + 1).fill().map(() => []);
    
    const BFS = (cnt, startNode, cutNode) => {
        let queue = [];
        let visited = new Array(n + 1).fill(false);
        
        queue.push(startNode);
        visited[startNode] = true;
        visited[cutNode] = true;
        
        while(queue.length !== 0) {
            let cur = queue.shift();
            
            for(const next of lines[cur]) {
                if(visited[next])
                    continue;
                
                cnt++;
                queue.push(next);
                visited[next] = true;
            }
        }
        
        return cnt;
    }
    
    for(const [a, b] of wires) {
        lines[a].push(b);
        lines[b].push(a);
    }
    
    for(const [a, b] of wires) {
        let cnt = BFS(1, a, b);
        answer = Math.min(answer, Math.abs(cnt - (n - cnt)));
    }
    
    return answer;
}