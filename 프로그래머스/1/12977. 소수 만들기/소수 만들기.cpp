#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    vector<int> tmp;
    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+1; j<nums.size()-1; j++){
            for(int k=j+1; k<nums.size(); k++){
                tmp.push_back(nums[i]+nums[j]+nums[k]);
            }
        }
    }
    
    for(int i=0; i<tmp.size(); i++){
        if(isPrime(tmp[i]))
            answer++;
    }

    return answer;
}