function solution(weights) {
    let answer = 0;
    
    const cnt = Array.from({length: 1001}, () => 0);
    
    // 몸무게 인원 체크
    for(let i = 0; i < weights.length; i++)
        cnt[weights[i]]++;
    
    // 2:3, 2:4(1:2), 3:4
    for(let i = 0; i < weights.length; i++){
        if(weights[i] % 2 === 0){
            let check = (weights[i] / 2) * 3;
            if(check <= 1000)
                answer += cnt[check];
        }
        
        if(weights[i] % 3 === 0){
            let check = (weights[i] / 3) * 4;
            if(check <= 1000)
                answer += cnt[check];
        }
        
        let check = weights[i] * 2;
        if(check <= 1000)
            answer += cnt[check];
    }
    
    for(let i = 100; i <= 1000; i++){
        if(cnt[i] >= 2)
            answer += cnt[i] * (cnt[i] - 1) / 2;
    }
    
    return answer;
}