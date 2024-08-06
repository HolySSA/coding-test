function GCD(a, b){
    if(a%b === 0)
        return b;
    
    return GCD(b, a % b);
}

function solution(arr) {
  return arr.reduce((a, b) => (a*b) / GCD(a, b));
}