#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    string str = "";
    
    for(auto n : numbers){
        str = "";
        
        if(n == 0){
            answer.push_back(1);
            continue;
        }
        
        while(n > 0){
            str += to_string(n%2);
            n /= 2;
        }
        
        long long cnt=0;
        for(int i=0; i<str.length(); i++){
            // 하단에서 0을 1로 바꾸는게 베스트(reverse 기준)
            if(str[i] == '0'){
                str[i] = '1';
                cnt = i-1;
                break;
            }
            
            // 0이 없을 경우 상단에 1추가(reverse 기준)
            if(i == str.length()-1){
                str += '1';
                cnt = i;
                break;
            }
        }
        
        for(int i=cnt; i>=0; i--){
            if(str[i] == '1'){
                str[i] = '0';
                break;
            }
        }
        
        long long sum = 0;
        for(int i=0; i<str.length(); i++)
            sum += (str[i]-'0') * pow(2, i);
        
        answer.push_back(sum);
    }
    
    return answer;
}