function solution(a, b) {
    var answer = '';
    
    let date = [ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ];
    let day = [ "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" ];
    
    let sum = 0;
    for(let i=1; i<a; i++){
        sum += date[i-1];
    }
    
    sum += b-1;
    sum %= day.length;
    
    answer = day[sum];
    return answer;
}