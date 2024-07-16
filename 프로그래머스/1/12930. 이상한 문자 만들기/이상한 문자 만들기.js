function solution(s) {
    let answer = '';
    
    let tmp = s.split(' ');
    
    for(let i=0; i<tmp.length; i++){
        for(let j=0; j<tmp[i].length; j++){
            if(j%2 == 0)
                answer += tmp[i][j].toUpperCase();
            else
                answer += tmp[i][j].toLowerCase();
        }
        
        if(i < tmp.length-1)
            answer += ' ';
    }
    
    return answer;
}