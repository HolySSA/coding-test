function solution(t, p) {
    let answer = 0;
    
    let t_number = Number(t);
    let p_number = Number(p);
    
    for(let i=0; i<t.length-p.length+1; i++){
        let comp_num = t.slice(i, i+p.length);
        
        if(comp_num <= p_number)
            answer++;
    }
    
    return answer;
}