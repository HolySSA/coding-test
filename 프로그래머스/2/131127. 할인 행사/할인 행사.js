function solution(want, number, discount) {
    var answer = 0;
    
    let Check = ((arr) => {
        var tmp = new Map();
        arr.forEach((a) => tmp.set(a, (tmp.get(a) || 0) + 1));
        for(let i=0; i<want.length; i++){
            if(tmp.get(want[i]) !== number[i])
                return false;
        }
        
        return true;
    });
  
    for(let i=0; i<=discount.length-10; i++){
      var check = discount.slice(i, i+10);
      if(Check(check))
          answer++;
    }
    
    return answer;
}