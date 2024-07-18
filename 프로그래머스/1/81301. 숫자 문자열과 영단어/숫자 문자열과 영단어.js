function solution(s) {
    var answer = 0;
    
    let word = [ "zero",  "one",  "two",  "three",  "four",  "five",  "six",  "seven", "eight", "nine" ];
    
    let complete_str = "";
    let compare_str = "";
    for(let i=0; i<s.length; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            complete_str += s[i];
            continue;
        }
        
        compare_str += s[i];
        
        for(let j=0; j<word.length; j++){
            if(compare_str === word[j]){
                complete_str += j.toString();
                compare_str = "";
                break;
            }
        }
    }
    
    answer = parseInt(complete_str, 10);
    
    return answer;
}