const allCases = [];

function isEqual(a, b, c) {
    return a === b && b === c;
}
    
function finishGame(board) {
    for(let i = 0; i < 3; i++) {
        if(isEqual(board[i][0], board[i][1], board[i][2]) && board[i][0] !== '.')
            return true;
    }

    for(let i = 0; i < 3; i++) {
        if(isEqual(board[0][i], board[1][i], board[2][i]) && board[0][i] !== '.')
            return true;
    }

    if(isEqual(board[0][0], board[1][1], board[2][2]) && board[0][0] !== '.')
            return true;
    if(isEqual(board[0][2], board[1][1], board[2][0]) && board[1][1] !== '.')
            return true;

    return false;
}

function nextTurn(turn) {
    return turn === 'O' ? 'X' : 'O';
}

function bruteforce(cnt, turn, board) {
    allCases.push(board.map(row => [...row]));
    
    if(cnt === 9 || finishGame(board))
        return;
    
    for(let i = 0; i < 9; i++) {
        let r = Math.floor(i / 3);
        let c = i % 3;
        
        if(board[r][c] !== '.')
            continue;
        
        // 백트래킹
        board[r][c] = turn;
        bruteforce(cnt + 1, nextTurn(turn), board);
        board[r][c] = '.';
    }
}

function isSame(a, b) {
    for(let i = 0; i < 3; i++) {
        for(let j = 0; j < 3; j++) {
            if(a[i][j] !== b[i][j])
                return false;
        }
    }
    
    return true;
}

function solution(board) {
    let answer = 0;
    
    const initBoard = [['.', '.', '.'], ['.', '.', '.'], ['.', '.', '.']];
    
    // 브루트 포스로 모든 경우의 수 체크
    bruteforce(0, 'O', initBoard);
    
    for(const curCase of allCases) {
        if(isSame(curCase, board)) {
            answer = 1;
            break;
        }
    }
    
    return answer;
}