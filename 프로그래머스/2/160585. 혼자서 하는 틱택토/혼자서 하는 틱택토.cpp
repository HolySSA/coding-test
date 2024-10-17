#include <string>
#include <vector>

using namespace std;

vector<vector<string>> allCases;

bool equal(char a, char b, char c) {
    return a == b && b == c;
}

bool gameEnd(vector<string> board) {
    for(int i = 0; i < 3; i++) {
        if(equal(board[i][0], board[i][1], board[i][2]) && board[i][0] != '.')
            return true;
    }
    for(int i = 0; i < 3; i++) {
        if(equal(board[0][i], board[1][i], board[2][i]) && board[0][i] != '.')
            return true;
    }
    if(equal(board[0][0], board[1][1], board[2][2]) && board[0][0] != '.')
        return true;
    if(equal(board[0][2], board[1][1], board[2][0]) && board[1][1] != '.')
        return true;
    
    return false;
}

char nextTurn(char turn) {
    if(turn == 'O')
        return 'X';
    else
        return 'O';
}

void bruteforce(int cnt, char turn, vector<string> board) {
    allCases.push_back(board);
    
    if(cnt == 9 || gameEnd(board))
        return;
    
    for(int i = 0; i < 9; i++) {
        int r = i / 3;
        int c = i % 3;
        
        if(board[r][c] != '.')
            continue;
        
        // 백트래킹
        board[r][c] = turn;
        bruteforce(cnt + 1, nextTurn(turn), board);
        board[r][c] = '.';
    }
}

bool sameCase(vector<string> &a, vector<string> &b) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(a[i][j] != b[i][j])
                return false;
        }
    }
    
    return true;
}

int solution(vector<string> board) {
    vector<string> initBoard;
    for(int i = 0 ; i < 3; i++)
        initBoard.push_back("...");
    // 브루트 포스로 모든 경우의 수 구하기
    bruteforce(0, 'O', initBoard);
    
    for(auto canCase: allCases) {
        if (sameCase(board, canCase))
            return 1;
    }
    
    return 0;
}