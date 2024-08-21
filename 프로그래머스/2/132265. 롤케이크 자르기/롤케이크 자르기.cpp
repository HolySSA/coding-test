#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int cnt = 0;
    map<int, int> oldBro;
    map<int, int> youngBro;
    
    for(auto t : topping)
        youngBro[t]++;
    
    for(int i=0; i<topping.size()-1; i++){
        oldBro[topping[i]]++;
        youngBro[topping[i]]--;
        
        if(youngBro[topping[i]] == 0)
            youngBro.erase(topping[i]);
        
        if(oldBro.size() == youngBro.size())
            answer++;
    }
    
    return answer;
}