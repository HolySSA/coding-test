#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> cnt;
    for(int i=0; i<want.size(); i++)
        cnt[want[i]] = number[i];
 
    for(int i=0; i<=discount.size()-10; i++){
        map<string, int> check;
        for(int j=i; j<i+10; j++)
            check[discount[j]]++;

        if(check == cnt)
            answer++;
    }
    
    return answer;
}