function solution(ingredient) {
    var answer = 0;
    
    let burgur = [];
    
    [...ingredient].forEach((ing) => {
        if(burgur[burgur.length-1] === 1 && ing === 2)
            burgur[burgur.length-1] = 12
        else if(burgur[burgur.length-1] === 12 && ing === 3)
            burgur[burgur.length-1] = 123
        else if(burgur[burgur.length-1] === 123 && ing === 1){
            burgur.pop();
            answer++;
        }
        else
            burgur.push(ing);       
    })
    
    return answer;
}