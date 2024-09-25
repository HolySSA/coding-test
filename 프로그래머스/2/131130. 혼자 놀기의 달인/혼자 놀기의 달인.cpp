#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(int a, int b) {
    return a > b;
}

int solution(vector<int> cards) {
    vector<int> answers;
    vector<bool> check(cards.size(), false);
    
    for(int i = 0; i < cards.size(); i++) {
        int cur = cards[i];
        int cnt = 0;
        while(!check[cur - 1]) {
            check[cur - 1] = true;
            cur = cards[cur - 1];
            cnt++;
        }
        
        if(cnt)
            answers.push_back(cnt);
    }
    
    sort(answers.begin(), answers.end(), Comp);
    if(answers.size() > 1)
        return answers[0] * answers[1];
    
    return 0;
}