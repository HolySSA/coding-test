function solution(line) {
    let answer = [];
    
    let intersection = [];
    
    function star(idx) {
        for(let i = idx + 1; i < line.length; i++) {
            let denominator = line[idx][0] * line[i][1] - line[idx][1] * line[i][0];
            
            if(denominator === 0)
                continue;
            
            let x = (line[idx][1] * line[i][2] - line[idx][2] * line[i][1]) / denominator;
            let y = (line[idx][2] * line[i][0] - line[idx][0] * line[i][2]) / denominator;
            
            if(Number.isInteger(x) && Number.isInteger(y))
                intersection.push({ x, y });
        }
    }
    
    for(let i = 0; i < line.length - 1; i++)
        star(i);
    
    let minX = Infinity;
    let maxX = -Infinity;
    let minY = Infinity;
    let maxY = -Infinity;
    
    for(const i of intersection) {
        minX = Math.min(minX, i.x);
        maxX = Math.max(maxX, i.x);
        minY = Math.min(minY, i.y);
        maxY = Math.max(maxY, i.y);
    }
    
    for(let y = minY; y <= maxY; y++) {
        let row = '';
        for(let x = minX; x <= maxX; x++) {
            row += '.';
        }
        
        answer.push(row);
    }
    
    for(const i of intersection) {
        let row = answer[maxY - i.y].split('');
        row[i.x - minX] = '*';
        answer[maxY - i.y] = row.join('');
    }
    
    return answer;
}