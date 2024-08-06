#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int A, int B) {
    if (A % B == 0)
        return B;
    else
        return GCD(B, A % B);
}

int solution(vector<int> arr) {
    int answer = 1;
    
    sort(arr.begin(), arr.end());
    
    for(int i=1; i<arr.size(); i++)
    {
        int gcd = GCD(answer, arr[i]);
        int lcm = answer * arr[i] / gcd;
        answer = lcm;
    }
    
    return answer;
}