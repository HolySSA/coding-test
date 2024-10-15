function solution(name) {
    let answer = 0;
    
    let cnt = 0;
    let move = name.length - 1;
    
    for(let i = 0; i < name.length; i++) {
        answer += Math.min(name[i].charCodeAt() - 'A'.charCodeAt(), + 'Z'.charCodeAt() - name[i].charCodeAt() + 1);
        
        let idx = i + 1;
        while(idx < name.length) {
            if(name[idx] === 'A')
                idx++;
            else
                break;
        }
        
        cnt = name.length - 1 - (idx - 1);
        move = Math.min(move, i + cnt + Math.min(i, cnt));
    }
    
    return answer + move;
}