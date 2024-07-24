function solution(X, Y) {
    var answer = '';
    
    let x_cnt = [0,0,0,0,0,0,0,0,0,0];
    let y_cnt = [0,0,0,0,0,0,0,0,0,0];
    
    for(let i=0; i<X.length; i++)
        x_cnt[X[i]-'0']++;
    for(let i=0; i<Y.length; i++)
        y_cnt[Y[i]-'0']++;
    
    for(let i=9; i>=0; i--){
        let check_cnt = Math.min(x_cnt[i], y_cnt[i]);
        
        while(check_cnt > 0){
            answer += i.toString();
            check_cnt--;
        }
    }
    
    if(answer === '')
        answer = '-1';
    
    if(answer[0] === '0')
        answer = '0';
    
    return answer;
}