#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter){
    vector<string> str;
    stringstream ss(input);
    string temp;
 
    while(getline(ss, temp, delimiter))
        str.push_back(temp);
 
    return str;
}

string solution(string s) {
    string answer = "";
    
    vector<string> v = split(s, ' ');
    
    int max_num = -2e9, min_num = 2e9;
    for(int i=0; i<v.size(); i++){
        max_num = max(max_num, stoi(v[i]));
        min_num = min(min_num, stoi(v[i]));
    }
    
    answer = to_string(min_num) + ' ' + to_string(max_num);
    
    return answer;
}