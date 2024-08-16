#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0)
			return false;
	}
    
	return true;
}

string Conversion(int n, int k){
    string str = "";
    
    while(n > 0){
        str += to_string(n%k);
        n /= k;
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

int solution(int n, int k) {
    int answer = 0;
    
    string con = Conversion(n, k);
    
    string tmp = "";
    for(int i=0; i<con.length(); i++){
        if(con[i] == '0'){
            if(tmp == "" || tmp == "1"){
                tmp = "";
                continue;
            }
            
            if(isPrime(stoll(tmp))){
                tmp = "";
                answer++;
            }
            else
                tmp = "";
        }
        else
            tmp += con[i];
    }
    
    if(tmp != "" && tmp != "1" && isPrime(stoll(tmp)))
        answer++;
    
    return answer;
}