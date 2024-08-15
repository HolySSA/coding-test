function solution(k, dungeons) {
    let answer = -1;
    let visited = [];
    
    function DFS(cnt, k){
        if(cnt > answer)
            answer = cnt;
        
        for(let i=0; i<dungeons.length; i++){
            if(visited[i])
                continue;
            if(dungeons[i][0] > k)
                continue;
            
            visited[i] = true;
            DFS(cnt+1, k-dungeons[i][1]);
            visited[i] = false;
        }
    }
    
    DFS(0, k);
    
    return answer;
}