function solution(s, n) {
    let alphabet = s.split("");
    let tmp = [];
    let answer = "";
    
    alphabet.forEach((el, idx) => {
        if (s.charCodeAt(idx) === 32) {
            tmp.push(String.fromCharCode(32));
            return;
        }
        
        // 아스키코드
        let charCode = s.charCodeAt(idx);
        
        if (charCode >= 65 && charCode <= 90)
            charCode = charCode + n > 90 ? charCode + n - 26 : charCode += n;

        if (charCode >= 97 && charCode <= 122)
            charCode = charCode + n > 122 ? charCode + n - 26 : charCode += n;
        
        tmp.push(String.fromCharCode(charCode));
    });
    
    answer = tmp.join("");
    
    return answer;
}