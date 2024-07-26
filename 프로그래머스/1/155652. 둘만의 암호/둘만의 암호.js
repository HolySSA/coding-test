function solution(s, skip, index) {
    var answer = '';
    
    [...s].forEach((c) => {
        let i_c = c.charCodeAt();
        for(let i=1; i<=index; i++){
            i_c++;
            
            if(i_c == 123)
                i_c = 97;
            
            while(skip.includes(String.fromCharCode(i_c))){
                i_c++;
                
                if(i_c == 123)
                    i_c = 97;
            }
        }
        
        answer += String.fromCharCode(i_c);
    });
    
    return answer;
}