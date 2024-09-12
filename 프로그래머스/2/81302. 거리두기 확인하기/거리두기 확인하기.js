function solution(places) {
    let answer = [];
    
    function Distance(r, c, place) {
        if(r + 1 < place.length) {
            if(place[r+1][c] === 'P')
                return false;
        }
        if(r + 2 < place.length) {
            if(place[r+1][c] !== 'X' && place[r+2][c] === 'P')
                return false;
        }
        if(c + 1 < place[0].length) {
            if(place[r][c+1] === 'P')
                return false;
        }
        if(c + 2 < place[0].length) {
            if(place[r][c+1] !== 'X' && place[r][c+2] === 'P')
                return false;
        }
        if(r + 1 < place.length && c - 1 >= 0) {
            if(place[r+1][c-1] === 'P' && (place[r+1][c] !== 'X' || place[r][c-1] !== 'X'))
                return false;
        }
        if(r + 1 < place.length && c + 1 < place[0].length) {
            if(place[r+1][c+1] === 'P' && (place[r+1][c] !== 'X' || place[r][c+1] !== 'X'))
                return false;
        }
        
        return true;
    }
    
    for(const place of places) {
        let check = false;
        for(let r = 0; r < place.length; r++) {
            for(let c = 0; c < place[0].length; c++) {
                if(place[r][c] === 'P') {
                    if(!Distance(r, c, place))
                        check = true;
                }
            }
        }
        
        if(check)
            answer.push(0);
        else
            answer.push(1);
    }
    
    return answer;
}