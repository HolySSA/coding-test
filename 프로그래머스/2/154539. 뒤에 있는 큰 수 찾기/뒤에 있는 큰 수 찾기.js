function solution(numbers) {
    var answer = new Array(numbers.length).fill(-1);
    
    let st = [];
    
    for(let i=numbers.length-1; i>=0; i--){
        while(1){
            if(st.length === 0){
                answer[i] = -1;
                break;
            }
            if(st[st.length-1] > numbers[i]){
                answer[i] = st[st.length-1];
                break;
            }
            
            st.pop();
        }
        
        st.push(numbers[i]);
    }
    
    return answer;
}