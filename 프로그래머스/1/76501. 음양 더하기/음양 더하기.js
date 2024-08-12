function solution(absolutes, signs) {
    var answer = 0;
    
    for(let i=0; i<signs.length; i++){
        if(!signs[i])
            absolutes[i] *= -1;
        
        answer += absolutes[i];
    }
    
    return answer;
}