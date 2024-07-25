function solution(keymap, targets) {
    var answer = [];
    let cnt = new Map();
    
    // Map에 해당 keymap 알파벳 카운트 저장
    for(let i=0; i<keymap.length; i++){
        for(let j=0; j<keymap[i].length; j++){
            // 카운트가 할당되지 않았거나, 할당된 카운트가 더 클 경우
            if(!cnt[keymap[i][j]] || cnt[keymap[i][j]] > j)
                cnt[keymap[i][j]] = j+1;
        }
    }
    
    for(let target of targets){
        let sum = 0;
        for(let i=0; i<target.length; i++){
            // 해당 알파벳이 MAP에 할당되어 있지 않을 경우
            if(!cnt[target[i]]){
                sum = -1;
                break;
            }
            
            // 해당 알파벳 카운트 더하기
            sum += cnt[target[i]];
        }
        
        answer.push(sum)
    }
    
    return answer;
}