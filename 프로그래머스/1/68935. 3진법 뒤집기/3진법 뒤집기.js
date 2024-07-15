function solution(n) {
    var answer = 0;
    
    let trinary = n.toString(3);
    let triReverse = trinary.split("").reverse().join("");

    answer = parseInt(triReverse, 3);
    
    return answer;
}