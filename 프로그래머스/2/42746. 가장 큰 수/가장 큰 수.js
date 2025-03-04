function solution(numbers) {
    let answer = numbers.map((numbers) => String(numbers)).sort((a,b) => {
        return (b+a) - (a+b)
    }).join('');
    
    return answer[0] === '0' ? '0' : answer;
}