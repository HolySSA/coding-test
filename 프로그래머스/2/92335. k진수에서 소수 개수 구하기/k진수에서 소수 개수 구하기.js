function isPrime(n) {
    if (n <= 1)
        return false;

    for (let i = 2; i <= Math.sqrt(n); i++) {
        if (n % i === 0)
            return false;
    }
    
    return true;
}

function solution(n, k) {
    let answer = 0;
    let str = n.toString(k);
    let arr = str.split("0"); // 0으로 나눠서 배열 저장

    for (let i=0; i<arr.length; i++) {
        if (isPrime(Number(arr[i])))
            answer++;
    }
    
    return answer;
}