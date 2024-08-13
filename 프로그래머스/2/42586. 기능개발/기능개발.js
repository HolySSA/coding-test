function solution(progresses, speeds) {
    var answer = [];
    
    let remain = progresses.map((p, index) => {
        return Math.ceil((100-p) / speeds[index]);
    });
    
    let s=remain[0], cnt=1;
    for(let i=1; i<remain.length; i++){
        if(s >= remain[i])
            cnt++;
        else{
            s=remain[i];
            answer.push(cnt);
            cnt=1;
        }
    }
    
    let sum=0;
    for(d in remain)
        sum += d;
    
    if(sum !== progresses.length)
        answer.push(cnt);
    
    return answer;
}