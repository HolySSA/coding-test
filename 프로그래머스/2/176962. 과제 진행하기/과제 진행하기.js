function solution(plans) {
    let answer = [];
    
    plans.sort((a, b) => convertM(a) - convertM(b));
    
    for(const plan of plans)
        console.log(plan[0]);
    
    function convertM(plan) {
        const time = plan[1].split(':');
        
        return parseInt(time[0]) * 60 + parseInt(time[1]);
    }
    
    let tmp = [];
    let time = 0;
    for(const plan of plans) {
        let start = convertM(plan);
        while (time < start) {
            if(tmp.length !== 0){
                tmp[tmp.length - 1][2]--;
                
                if(tmp[tmp.length - 1][2] === 0) {
                    answer.push(tmp[tmp.length - 1][0]);
                    tmp.pop();
                }
            }

            time++;
        }
        
        tmp.push(plan);
    }

    while(tmp.length !== 0) {
        answer.push(tmp[tmp.length - 1][0]);
        tmp.pop();
    }
    
    return answer;
}