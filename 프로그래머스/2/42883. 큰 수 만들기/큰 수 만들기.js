function solution(number, k) {
    let answer = '';
    
    let tmp = [];
    for(let i=0; i<number.length; i++){
        while(k>0 && number[i] > tmp[tmp.length-1]){
            tmp.pop();
            k--;
        }
        
        if(tmp.length < number.length-k)
            tmp.push(number[i]);
    }
    
    answer = tmp.join('');
    
    return answer;
}