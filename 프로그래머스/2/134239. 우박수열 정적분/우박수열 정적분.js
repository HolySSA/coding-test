function solution(k, ranges) {
    let answer = [];
    let areas = [];
    
    while(k !== 1) {
        if(k % 2 === 0) {
            k /= 2;
            areas.push(k * 1.5);
        }
        else {
            let tmp = k;
            k = k * 3 + 1;
            areas.push(tmp + (k - tmp) * 0.5);
        }
    }
    
    for(const range of ranges) {
        let start = range[0];
        let finish = areas.length + range[1];
        
        if(start > finish) {
            answer.push(-1.0);
            continue;
        }
        if(start === finish) {
            answer.push(0.0);
            continue;
        }
        
        let sum = 0;
        for(let i = start; i < finish; i++) {
            sum += areas[i];
        }
        answer.push(sum);
    }
    
    return answer;
}