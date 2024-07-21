#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int cards1_idx = 0, cards2_idx = 0;
    while (cards1_idx + cards2_idx < goal.size()) {
        if (cards1_idx < cards1.size() && cards1[cards1_idx] == goal[cards1_idx + cards2_idx])
            cards1_idx++;
        else if (cards2_idx < cards2.size() && cards2[cards2_idx] == goal[cards1_idx + cards2_idx])
            cards2_idx++;
        else
            return "No";
    }
    
    return "Yes";
}