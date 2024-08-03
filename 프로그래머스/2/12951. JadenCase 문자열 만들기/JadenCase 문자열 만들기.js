function solution(s) {
    var answer = '';
    
    let word = s.split(' ');

    let convert = word.map((str) => {
        return str.charAt(0).toUpperCase() + str.slice(1).toLowerCase();
    });

    answer = convert.join(' ');
    return answer;
}