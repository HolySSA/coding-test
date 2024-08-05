#include <string>
#include <vector>
#define MAX 100000
#define DIV 1234567
using namespace std;

int solution(int n) {
    unsigned long long fib[MAX];
    
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i=2; i<=n; i++)
        fib[i] = (fib[i-1]%DIV + fib[i-2]%DIV)%DIV;
    
    return fib[n];
}