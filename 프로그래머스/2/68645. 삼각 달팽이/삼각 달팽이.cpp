#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> snail(n+1, vector<int>(n+1));
    
    int val = 1, y = 1, x = 1;
    for(int i=1; i<=n; i++){
        if(i%3 == 1){
            for(int j=i; j<=n; j++)
				snail[y++][x] = val++;

			y--;
			x++;
        }
        else if(i%3 == 2){
            for(int j=i; j<=n; j++)
				snail[y][x++] = val++;

			y--;
			x -= 2;
        }
        else if(i%3 == 0){
            for(int j=i; j<=n; j++)
				snail[y--][x--] = val++;

			y += 2;
			x++;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            answer.push_back(snail[i][j]);
    }
    
    return answer;
}