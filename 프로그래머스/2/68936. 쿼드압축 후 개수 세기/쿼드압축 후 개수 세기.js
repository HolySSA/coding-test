function solution(arr) {
    let answer = [];
    
    let zero=0, one=0;
    
    function Check(x, y, size){
        if(size === 0)
            return;
        
        let zeroCheck=true;
        let oneCheck=true;
        
        for(let i=y; i<y+size; i++){
            for(let j=x; j<x+size; j++){
                if(arr[i][j] === 0)
                    oneCheck = false;
                if(arr[i][j] === 1)
                    zeroCheck = false;
                
                if(!(oneCheck || zeroCheck))
                    break;
            }
            
            if(!(oneCheck || zeroCheck))
                break;
        }
        
        if(oneCheck){
            one++;
            return;
        }
        if(zeroCheck){
            zero++;
            return;
        }
        
        Check(x, y, size/2);
        Check(x+size/2, y, size/2);
        Check(x, y+size/2, size/2);
        Check(x+size/2, y+size/2, size/2);
    }
    
    Check(0, 0, arr.length, arr);
    answer.push(zero);
    answer.push(one);
    return answer;
}