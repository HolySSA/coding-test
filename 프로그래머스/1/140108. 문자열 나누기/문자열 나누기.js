function solution(s) {
    var answer = 0;
    
    let same = 0, differ = 0;
    let x = "";
    
    for(let i=0; i<s.length; i++){
        if(x === ""){
            x = s[i];
            same++;
            continue;
        }
        
        if(s[i] === x)
            same++;
        else
            differ++;
        
        if(same === differ){
            x = "";
            same = 0, differ = 0;
            answer++;
        }
    }
    
    if(same !== 0)
        answer++;
    
    return answer;
}