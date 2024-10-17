function GCD(a, b) {
    if(a % b === 0)
        return b;

    return GCD(b, a % b);
}

function solution(w, h) {
    let answer = w * h;
    const gcd = GCD(w, h);
    
    answer -= w + h - gcd;
    
    return answer;
}