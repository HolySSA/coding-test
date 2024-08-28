function solution(numbers) {
    var answer = 0;
    let tmp = new Set();
    
    function isPrime(num) {
        if(num <= 1)
            return false;
        if(num === 2 || num === 3)
            return true;
        
        for(let i=2; i<=Math.sqrt(num); i++) {
           if(num%i === 0)
               return false;
        }
        
        return true;
    }
    
    function permutation(arr, result) {
        if(arr.length >= 1) {
            for(let i=0; i<arr.length; i++){
                let nResult = result + arr[i];
                let nArr = [...arr];
                nArr.splice(i, 1);
                
                // set 자동으로 중복 제거
                if(isPrime(Number(nResult)))
                    tmp.add(Number(nResult));
                
                permutation(nArr, nResult);
            }
        }
    }
    
    permutation(numbers, "");
    
    answer = tmp.size;
    return answer;
}