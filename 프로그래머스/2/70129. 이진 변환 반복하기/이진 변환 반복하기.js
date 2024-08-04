function solution(s) {
    var answer = [0, 0];
    
    let s_length = 0;
    while (s.length > 1) {
        s_length = s.length;
        
        s = s.split("0").join("");
        
        answer[0]++; // cnt
        answer[1] += s_length - s.length; // zero (원래 크기 - 0을 뺀 크기 = 0 크기)
      
        s = s.length.toString(2); // 2진수 문자열로
    }
    
    return answer;
}