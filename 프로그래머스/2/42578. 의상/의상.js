function solution(clothes) {
    var answer = 1;
    
    let comb = new Map();
    // map에 종류별 개수 담기
    clothes.forEach((s) => comb.set(s[1], (comb.get(s[1]) || 0) + 1));
    // 갯수 세기 (입지 않은 경우까지 더해서 조합)
    for(v of comb.values())
        answer *= v+1;
    // 아무 것도 안 입은 경우 제외
    return --answer;
}