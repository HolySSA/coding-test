#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer { 0, 1000001 };
    
    // start, end, sum
    int s=0, e=0, sum=0;
    for(int i=0; i<sequence.size(); i++){
        sum += sequence[s++];
        
        if(sum > k){
            while(sum-sequence[e] >= k)
                sum -= sequence[e++];
        }
        
        if(sum == k){
            if(answer[1]-answer[0] > s-e-1)
                answer = { e, s-1 };
        }
    }
    
    return answer;
}