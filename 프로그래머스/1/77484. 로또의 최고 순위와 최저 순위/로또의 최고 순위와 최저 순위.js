function solution(lottos, win_nums) {
    var answer = [];
    
    let correct = lottos.filter((lotto) => win_nums.includes(lotto)).length;
    
    let zero_nums = lottos.filter((lotto) => lotto === 0).length;
    
    let min = 7-correct >= 6 ? 6 : 7-correct;
    let max = min-zero_nums < 1 ? 1 : min-zero_nums;
    
    answer.push(max);
    answer.push(min);
    
    return answer;
}