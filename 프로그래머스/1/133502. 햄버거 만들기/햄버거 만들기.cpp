#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> burgur; 
    for(auto ing : ingredient){
        if(burgur.empty()){
            burgur.push_back(ing);
            continue;
        }
        
        if(burgur.back() == 1 && ing == 2)
            burgur.back() = 12;
        else if(burgur.back() == 12 && ing == 3)
            burgur.back() = 123;
        else if(burgur.back() == 123 && ing == 1){
            burgur.pop_back();
            answer++;
        }
        else
            burgur.push_back(ing);
    }
    
    return answer;
}