function solution(k, score) {
    var answer = [];
    let rank = [];
     score.forEach(num => {
        rank.push(num);
        // 정렬하고 k개로 분할
        rank.sort((a,b) => b-a).splice(k);
         // 최솟값 넣기
        answer.push(Math.min.apply(null, rank));
    });
    
    return answer;
}