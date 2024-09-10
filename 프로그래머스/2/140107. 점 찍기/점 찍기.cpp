#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double Distance (long long d, long long x) {
    return sqrt(pow(d, 2) - pow(x, 2));
}

long long solution(int k, int d) {
    long long answer = 0;
    
    int x = 0;
    while (x * k <= d) {
        int maxY = Distance(d, x * k);
        answer += (maxY / k) + 1;
        
        x++;
    }
    
    return answer;
}