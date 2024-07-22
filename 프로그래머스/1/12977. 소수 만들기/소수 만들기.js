function solution(nums) {
    var answer = 0;
    
    for(let i=0; i<nums.length-2; i++){
        for(let j=i+1; j<nums.length-1; j++){
            for(let k=j+1; k<nums.length; k++){
                let sum = nums[i]+nums[j]+nums[k];
                
                let check = true;
                for(let cnt=2; cnt <= Math.sqrt(sum); cnt++){
                    if(sum % cnt === 0)
                        check = false;
                }
                
                if(check)
                    answer++;
            }
        }
    }
    
    return answer;
}