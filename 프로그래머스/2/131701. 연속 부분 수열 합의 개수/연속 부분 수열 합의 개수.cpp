#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;

    set<int> nums;
    
    for(int i=0; i<elements.size(); i++){
        int sum = 0;
        // 원형 수열
        for(int j=i; j<i+elements.size(); j++){
            int idx = j % elements.size();
            // idx 기준으로 다음 원소를 더한 값을 계속해서 nums에 삽입
            sum += elements[idx];
            nums.emplace(sum);
        }
    }
    
    answer = nums.size();
    
    return answer;
}