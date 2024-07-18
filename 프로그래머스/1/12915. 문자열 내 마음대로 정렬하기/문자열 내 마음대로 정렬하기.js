function solution(strings, n) {
    var answer = [];
    
    strings.sort((a, b) => {
        if(a[n] === b[n])
            return a > b ? 1 : -1;
       
        return a[n] > b[n] ? 1 : -1;
        
    });
    
    answer = strings;
    
    return answer;
}