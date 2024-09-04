#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int TurnNum(vector<vector<int>> &board, int startR, int startC, int endR, int endC) {
    int minNum = board[startR][startC], tmp = board[startR][startC];
    
    // 왼 |
    for(int r = startR; r < endR; r++) {
        minNum = min(minNum, board[r][startC]);
        board[r][startC] = board[r + 1][startC];
    }
    // 아래 ㅡ
    for(int c = startC; c < endC; c++) {
        minNum = min(minNum, board[endR][c]);
        board[endR][c] = board[endR][c + 1];
    }
    // 오 |
    for(int r = endR; r > startR; r--) {
        minNum = min(minNum, board[r][endC]);
        board[r][endC] = board[r - 1][endC];
    }
    // 위 ㅡ
    for(int c = endC; c > startC; c--) {
        minNum = min(minNum, board[startR][c]);
        board[startR][c] = board[startR][c - 1];
    }
    
    board[startR][startC + 1] = tmp;
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int num = 1;
    vector<vector<int>> board(rows + 1, vector<int> (columns + 1));
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            board[i][j] = num++;
        }
    }
    
    int cur = 0, tmp = 0;
    for(int i = 0; i < queries.size(); i++)
        answer.push_back(TurnNum(board, queries[i][0], queries[i][1], queries[i][2], queries[i][3]));
    
    return answer;
}