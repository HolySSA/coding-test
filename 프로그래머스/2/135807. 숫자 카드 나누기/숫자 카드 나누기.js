function GCD(a, b) {
    if(a % b === 0)
        return b;
    
    return GCD(b, a % b);
}

function solution(arrayA, arrayB) {
    let answer = 0;
    
    let gcdA = arrayA[0], gcdB = arrayB[0];
    for(let i = 1; i < arrayA.length; i++) {
        gcdA = GCD(gcdA, arrayA[i]);
        gcdB = GCD(gcdB, arrayB[i]);
    }
    
    let checkA = true, checkB = true;
    for(let i = 0; i < arrayA.length; i++) {
        if(arrayB[i] % gcdA === 0)
            checkA = false;
        if(arrayA[i] % gcdB === 0)
            checkB = false;
    }
    
    if(checkA)
        answer = gcdA;
    if(checkB)
        answer = Math.max(answer, gcdB);
    
    return answer;
}