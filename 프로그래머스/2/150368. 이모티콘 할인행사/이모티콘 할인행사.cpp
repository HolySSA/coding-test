#include <string>
#include <vector>

using namespace std;

int emoticonPlus = 0;
int emoticonPrice = 0;

vector<int> sales = { 40, 30, 20, 10 };
vector<int> applies;

void saleApply(vector<vector<int>> users, vector<int> emoticons) {
    if(applies.size() == emoticons.size()) {
        int curPlus = 0;
        int curPrice = 0;
        
        for(int i = 0; i < users.size(); i++) {
            int sum = 0;
            
            for(int j = 0; j < emoticons.size(); j++) {
                if(users[i][0] <= applies[j]) {
                    int sale = emoticons[j] * (100 - applies[j]) / 100;
                    sum += sale;
                }
            }
            
            if(sum >= users[i][1])
                curPlus++;
            else
                curPrice = curPrice + sum;
        }
        
        if(emoticonPlus < curPlus) {
            emoticonPlus = curPlus;
            emoticonPrice = curPrice;
        }
        else if(emoticonPlus == curPlus && emoticonPrice < curPrice) {
            emoticonPrice = curPrice;
        }
        
        return;
    }
    
    for(int i = 0; i < sales.size(); i++) {
        applies.push_back(sales[i]);
        saleApply(users, emoticons);
        applies.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    saleApply(users, emoticons);
    
    answer.push_back(emoticonPlus);
    answer.push_back(emoticonPrice);
    
    return answer;
}