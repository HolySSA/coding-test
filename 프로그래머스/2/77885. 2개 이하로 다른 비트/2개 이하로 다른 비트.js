function solution(numbers) {
    return numbers.map((n) => {
        // 2진수 변환
        let str = '0' + n.toString(2);
        if(str[str.length-1] === '0')
            str = str.substring(0, str.length-1) + '1';
        else{
            let idx = str.lastIndexOf('01');
            // 01을 10으로 바꾸는게 해당 문제의 값을 구하는 베스트
            str = str.substring(0, idx) + '10' + str.substring(idx+2, str.length);
        }
        
        return parseInt(str, 2);
    });
}