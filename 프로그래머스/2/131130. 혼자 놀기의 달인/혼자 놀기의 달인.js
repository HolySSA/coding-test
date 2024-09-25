function solution(cards) {
    let answers = [];
    let check = new Array(cards.length).fill(false);
    
    for(let i = 0; i < cards.length; i++) {
        let cur = cards[i];
        let cnt = 0;
        while(!check[cur - 1]) {
            check[cur - 1] = true;
            cur = cards[cur - 1];
            cnt++;
        }
        
        if(cnt)
            answers.push(cnt);
    }
    
    answers.sort((a, b) => b - a);
    if(answers.length < 2)
        return 0;
    
    return answers[0] * answers[1];
}