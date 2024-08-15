#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int idx, int sum, vector<int> numbers, int target){
    if(idx == numbers.size()){
        if(sum == target)
            answer++;
        
        return;
    }
    
    DFS(idx+1, sum-numbers[idx], numbers, target);
    DFS(idx+1, sum+numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, numbers, target);
    return answer;
}