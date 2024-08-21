function solution(topping) {
    let answer = 0;
    
    const oldBro = new Set();
    const youngBro = new Set();
    
    const cnt = new Array(10001).fill(0);
    
    topping.forEach((t) => {
        youngBro.add(t);
        cnt[t]++;
    });
    
    topping.forEach((t) => {
        if(cnt[t] > 0)
            cnt[t]--;
        if(cnt[t] == 0)
            youngBro.delete(t);

        oldBro.add(t);

        if(oldBro.size === youngBro.size)
            answer++;
    });
    
    return answer;
}