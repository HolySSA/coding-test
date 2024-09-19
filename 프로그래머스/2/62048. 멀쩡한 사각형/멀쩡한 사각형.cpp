using namespace std;

long long GCD(int a, int b) {
    if(a % b == 0)
        return b;
    
    return GCD(b, a % b);
}

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    long long gcd = GCD(w, h);
    
    answer -= w + h - gcd;
    
    return answer;
}