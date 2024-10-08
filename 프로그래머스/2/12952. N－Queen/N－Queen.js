function solution(n) {
    let answer = 0;
    let board = new Array(n).fill(0);
    
    function check(row) {
        for(let i = 0; i < row; i++) {
            if(board[i] === board[row] || Math.abs(board[i] - board[row]) === row - i)
                return false;
        }
        
        return true;
    }
    
    function nQueen(node) {
        if(node === n)
            answer++;
        else {
            for(let i = 0; i < n; i++) {
                board[node] = i;
                
                if(check(node))
                    nQueen(node + 1);
            }
        }
    }
    
    nQueen(0);
    return answer;
}