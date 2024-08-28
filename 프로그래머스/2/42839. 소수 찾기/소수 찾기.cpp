#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    if(n == 0 || n == 1)
        return false;
    if(n == 2 || n == 3)
        return true;
    
	for (int i=2; i<=sqrt(n); i++) {
        if (n%i == 0)
			return false;
	}
    
	return true;
}

int solution(string numbers){
    int answer = 0;
    set<int> num_s;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        string tmp = "";
        for(int i=0; i<numbers.size(); i++){
            tmp += numbers[i];
            if(isPrime(stoi(tmp)))
                num_s.insert(stoi(tmp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    answer = num_s.size();
    
    return answer;
}