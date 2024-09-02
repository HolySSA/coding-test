function solution(queue1, queue2) {
    let answer = -1;
    
    let cnt=0, maxLeng=queue1.length+queue2.length;
    let total_queue = [...queue1, ...queue2];
    let sum1=0, sum2=0;
    queue1.forEach((num) => sum1 += num);
    queue2.forEach((num) => sum2 += num);

    let s1=0, e1=queue1.length-1, s2=queue1.length, e2=maxLeng-1;
    while(cnt <= maxLeng*2){
        if(sum1<sum2){
            sum2 -= total_queue[s2++ % maxLeng];
            sum1 += total_queue[++e1 % maxLeng];
        }
        else if(sum2<sum1){
            sum1 -= total_queue[s1++ % maxLeng];
            sum2 += total_queue[++e2 % maxLeng];  
        }
        else{
            answer = cnt;
            break;
        }
        
        cnt++;
    }
    
    return answer;
}