function solution(park, routes) {
    var answer = [];
    
    let height, width;
    
    for(let i=0; i<park.length; i++){
        for(let j=0; j<park[i].length; j++){
            if(park[i][j] === 'S')
                height = i, width = j;
        }
    }
    
    for(let i=0; i<routes.length; i++){
        let n = parseInt(routes[i].substring(routes[i].indexOf(' ')+1));
        let check = false;
        let tmpH = height, tmpW = width;

        if(routes[i][0] === 'E'){
           for(let j=0; j<n; j++){
               if(width === park[0].length-1 || park[height][width+1] === 'X'){
                   check = true;
                   break;
               }
               
               width++;
           }
        }
        if(routes[i][0] === 'W'){
           for(let j=0; j<n; j++){
               if(width === 0 || park[height][width-1] === 'X'){
                   check = true;
                   break;
               }
               
               width--;
           }
        }
        if(routes[i][0] === 'S'){
           for(let j=0; j<n; j++){
               if(height === park.length-1 || park[height+1][width] === 'X'){
                   check = true;
                   break;
               }
               
               height++;
           }
        }
        if(routes[i][0] === 'N'){
           for(let j=0; j<n; j++){
               if(height === 0 || park[height-1][width] === 'X'){
                   check = true;
                   break;
               }
               
               height--;
           }
        }
        
        if(check === true)
            height = tmpH, width = tmpW;
    }
    
    answer.push(height);
    answer.push(width);

    return answer;
}