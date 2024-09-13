#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    if(a % b == 0)
        return b;
    
    return GCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = arrayA[0], gcdB = arrayB[0];
    for(int i = 1; i < arrayA.size(); i++) {
        gcdA = GCD(gcdA, arrayA[i]);
        gcdB = GCD(gcdB, arrayB[i]);
    }
    
    bool checkA = true, checkB = true;
    for(int i = 0; i < arrayA.size(); i++) {
        if(arrayB[i] % gcdA == 0)
            checkA = false;
        if(arrayA[i] % gcdB == 0)
            checkB = false;
    }
    
    if(checkA)
        answer = gcdA;
    if(checkB)
        answer = max(answer, gcdB);
    
    return answer;
}