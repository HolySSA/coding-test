#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> fight(n + 1, vector<int>(n + 1, 0));
    
    for(int i = 0; i < results.size(); i++) {
        fight[results[i][0]][results[i][1]] = 1;
    }
    
    // 플로이드-와샬 알고리즘
    for(int k = 1; k <= n; k++) { // 중간
        for(int i = 1; i <= n; i++) { // 시작
            for(int j = 1; j <= n; j++) { // 끝
                if(fight[i][k] == 1 && fight[k][j] == 1) {
                    fight[i][j] = 1;
                }
            }
        }
    }
    
     for(int i = 1; i <= n; i++) {
        int temp = 0;
        for(int j = 1; j <= n; j++) {
            temp += fight[i][j];
            temp += fight[j][i];
        }
         
        if(temp == n-1)
            answer++;
    }
    
    return answer;
}