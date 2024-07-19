function solution(s) {
    var answer = [];
    
    answer.push(-1);
    for(let i=1; i<s.length; i++){
        let tmp = 10001;
        for(let j=0; j<i; j++){
            if(s[i] === s[j])
                tmp = i-j;
            
            if(j == i-1){
                if(tmp !== 10001)
                    answer.push(tmp);
                else
                    answer.push(-1);
            }
        }
    }
    
    return answer;
}