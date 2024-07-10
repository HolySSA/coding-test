function solution(arr, divisor) {
    var answer = [];
    arr.forEach((element) => {
        if (element % divisor === 0) {
          answer.push(element);
        }
    });

    answer.sort(function(a, b) {
        return a-b;
    });
    
    if(answer.length == 0){
        answer.push(-1);
    }
    return answer;
}