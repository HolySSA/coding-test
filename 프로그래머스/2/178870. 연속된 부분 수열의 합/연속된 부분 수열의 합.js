function solution(sequence, k) {
    let answer = [0, 1000001];
    
    let idx1=0, idx2=0, sum=0;
    for(let i=0; i<sequence.length; i++){
        sum += sequence[idx1++];
        
        if(sum > k){
            while(sum-sequence[idx2] >= k)
                sum -= sequence[idx2++];
        }
        
        if(sum === k){
            while(answer[1]-answer[0] > idx1-1-idx2)
                answer = [idx2, idx1-1];
        }
    }
    
    return answer;
}