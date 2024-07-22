function solution(answers) {
    var answer = [];
    
    let supoza1 = [1, 2, 3, 4, 5];
    let supoza2 = [2, 1, 2, 3, 2, 4, 2, 5];
    let supoza3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    let score = [0, 0, 0];
    
    for(let i=0; i<answers.length; i++){
        if(answers[i] === supoza1[i%supoza1.length])
            score[0]++;
        if(answers[i] === supoza2[i%supoza2.length])
            score[1]++;
        if(answers[i] === supoza3[i%supoza3.length])
            score[2]++;
    }
    
    const max_score = Math.max(...score);
    
    for(let i=0; i<score.length; i++){
        if(score[i] === max_score)
            answer.push(i+1);
    }
    
    return answer;
}