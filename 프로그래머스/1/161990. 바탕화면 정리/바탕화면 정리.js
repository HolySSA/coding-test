function solution(wallpaper) {
    var answer = [];
    
    let lux=51, luy=51, rdx=-1, rdy=-1;
    wallpaper.forEach((s, index) => {
        
        for(let i=0; i<s.length; i++){
            if(s[i] === '#'){
                lux = Math.min(lux, index);
                luy = Math.min(luy, i);
                rdx = Math.max(rdx, index+1);
                rdy = Math.max(rdy, i+1);
            }
        }
    });
    
    answer.push(lux);
    answer.push(luy);
    answer.push(rdx);
    answer.push(rdy);
    
    return answer;
}