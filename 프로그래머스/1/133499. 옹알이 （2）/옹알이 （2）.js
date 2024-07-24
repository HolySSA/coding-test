function solution(babbling) {
    var answer = 0;
    
    let talk = ["aya", "ye", "woo", "ma"];

    for (let i=0; i<babbling.length; i++) {
        for (let j=0; j<talk.length; j++) {
            // 같은 발음 연속으로 하면 break
            if (babbling[i].includes(talk[j].repeat(2)))
                break;
            
            // 해당 발음 떼어내고 띄어쓰기 넣어두기
            babbling[i] = babbling[i].split(talk[j]).join(" ");
        }
        
        // 띄어쓰기 떼어내고 ""(크기 할당X)넣기
        if (babbling[i].split(" ").join("").length === 0)
            answer++;
    }
    
    return answer;
}