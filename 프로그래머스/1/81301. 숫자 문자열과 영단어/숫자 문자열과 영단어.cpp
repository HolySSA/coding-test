#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> word = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    string complete_str = "";
    string compare_str = "";
    
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            complete_str += s[i];
            continue;
        }
        
        compare_str += s[i];
        
        for(int j=0; j<word.size(); j++){
            if(compare_str == word[j]){
                complete_str += to_string(j);
                compare_str = "";
                break;
            }
        }
    }
    
    answer = stoi(complete_str);
    
    return answer;
}