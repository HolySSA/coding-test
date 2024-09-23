#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> answer;

void hanoi(int cnt, int n, int from, int by, int to) {
    vector<int> tmp;
    
    if(n == 1) {
        tmp.push_back(from);
        tmp.push_back(to);
        answer.push_back(tmp);
        return;
    }

    hanoi(cnt + 1, n - 1, from, to, by); 
    
    tmp.push_back(from);
    tmp.push_back(to);
    answer.push_back(tmp);
    
    hanoi(cnt + 1, n - 1, by, from, to); 
}

vector<vector<int>> solution(int n) {      
    hanoi(0, n, 1, 2, 3);
    
    return answer;
}