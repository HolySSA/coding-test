function solution(rows, columns, queries) {
    let answer = [];
    
    let board = Array.from(Array(rows + 1), () => new Array(columns + 1));
    let num = 1;
    for(let r = 1; r <= rows; r++) {
        for(let c = 1; c <= columns; c++) {
            board[r][c] = num++;
        }
    }
    
    function TurnNum(startR, startC, endR, endC) {
        let minNum = board[startR][startC], tmp = board[startR][startC];
    
        // 왼 |
        for(let r = startR; r < endR; r++) {
            minNum = Math.min(minNum, board[r][startC]);
            board[r][startC] = board[r + 1][startC];
        }
        // 아래 ㅡ
        for(let c = startC; c < endC; c++) {
            minNum = Math.min(minNum, board[endR][c]);
            board[endR][c] = board[endR][c + 1];
        }
        // 오 |
        for(let r = endR; r > startR; r--) {
            minNum = Math.min(minNum, board[r][endC]);
            board[r][endC] = board[r - 1][endC];
        }
        // 위 ㅡ
        for(let c = endC; c > startC; c--) {
            minNum = Math.min(minNum, board[startR][c]);
            board[startR][c] = board[startR][c - 1];
        }

        board[startR][startC + 1] = tmp;
        return minNum;
    }
    
    for(let i = 0; i < queries.length; i++) {
        answer.push(TurnNum(queries[i][0], queries[i][1], queries[i][2], queries[i][3]));
    } 
    
    return answer;
}