function solution(picks, minerals) {
    let answer = 2e9;
    let mineralsFatigue = [[1, 1, 1], [5, 1, 1], [25, 5, 1]];
    
    let mineralsInt = [];
    for(const m of minerals) {
        if(m === 'diamond')
            mineralsInt.push(0);
        else if(m === 'iron')
            mineralsInt.push(1);
        else if(m === 'stone')
            mineralsInt.push(2);
    }
    
    function digUp(cur, sum) {
        let save = 0;
        let picksFatigue = [ 0, 0, 0 ];
        
        if(cur >= minerals.length || (picks[0] === 0 && picks[1] === 0 && picks[2] === 0)) {
            answer = Math.min(answer, sum);
            return;
        }
        
        for(let i = cur; i < cur + 5; i++) {
            if(i >= minerals.length) {
                save = i;
                break;;
            }
            
            picksFatigue[0] += mineralsFatigue[0][mineralsInt[i]];
            picksFatigue[1] += mineralsFatigue[1][mineralsInt[i]];
            picksFatigue[2] += mineralsFatigue[2][mineralsInt[i]];
            
            save = i;
        }
        
        for(let i = 0; i < 3; i++) {
            if(picks[i] !== 0){
                picks[i]--;
                digUp(save + 1, sum + picksFatigue[i]);
                picks[i]++;
            }
        }
    }
    
    digUp(0, 0);
    
    return answer;
}