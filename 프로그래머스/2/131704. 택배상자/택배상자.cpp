#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub;
    
    int idx = 0;
    for(int i=1; i<=order.size(); i++){
        sub.push(i);
        
        while(!sub.empty() && sub.top() == order[idx]){
            idx++;
            answer++;
            sub.pop();
        }
    }
    
    return answer;
}