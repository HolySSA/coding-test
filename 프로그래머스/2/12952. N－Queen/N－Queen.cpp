#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int board[12];

bool check(int row) {
    for(int i = 0; i < row; i++) {
        if(board[i] == board[row] || abs(board[i] - board[row]) == row - i)
            return false;
    }
    
    return true;
}

void nQueen(int node, int n) {
    if(node == n) {
        answer++;
    }
    else {
        for(int i = 0; i < n; i++) {
            board[node] = i;
            
            if(check(node))
                nQueen(node + 1, n);
        }
    }
}

int solution(int n) {
    nQueen(0, n);
    return answer;
}