function solution(s) {
    var answer = '';
    
    let tmp = s.split(' ');
    
    let max = -2e9, min = 2e9;
    for(let i=0; i<tmp.length; i++){
        max = Math.max(max, parseInt(tmp[i]));
        min = Math.min(min, parseInt(tmp[i]));
    }
    
    answer = min.toString() + ' ' + max.toString();
    
    return answer;
}