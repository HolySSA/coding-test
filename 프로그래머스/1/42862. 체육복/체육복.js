function solution(n, lost, reserve) {
    var answer = 0;
    
    let lost_student = lost.filter((student) => !reserve.includes(student)).sort((a, b) => a-b);
    let reserve_student = reserve.filter((student) => !lost.includes(student)).sort((a, b) => a-b);
    
    answer += n-lost_student.length;
    
    for(let i=0; i<reserve_student.length; i++){
        for(let j=0; j<lost_student.length; j++){
            if(reserve_student[i]-1 === lost_student[j] || reserve_student[i]+1 === lost_student[j]){
                lost_student[j] = -1;
                reserve_student[i] = -1;
                answer++;
                break;
            }
        }
    }
    
    return answer;
}