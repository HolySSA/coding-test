#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> tmp;
    for(auto num : numbers)
        tmp.push_back(to_string(num));
    
    sort(tmp.begin(), tmp.end(), Comp);
    
     if (tmp[0] == "0")
         return "0";
    
    for(auto s : tmp)
        answer += s;
    
    return answer;
}