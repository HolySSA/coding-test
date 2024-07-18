function solution(array, commands) {
    var answer = [];
    
    for(let i=0; i<commands.length; i++){
        let tmp = array.slice(commands[i][0] - 1, commands[i][1]);
        
        tmp.sort((a, b) => {
           return a > b ? 1 : -1; 
        });
        
        answer.push(tmp[commands[i][2]-1]);
    }
    
    return answer;
}