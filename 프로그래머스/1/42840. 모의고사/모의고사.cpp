#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> supoza1 = {1, 2, 3, 4, 5};
    vector<int> supoza2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> supoza3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int correct1 = 0, correct2 = 0, correct3 = 0;
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == supoza1[i%supoza1.size()])
            correct1++;
        if(answers[i] == supoza2[i%supoza2.size()])
            correct2++;
        if(answers[i] == supoza3[i%supoza3.size()])
            correct3++;
    }
    
    int max_correct = max({correct1, correct2, correct3});
    
    if(max_correct == correct1)
        answer.push_back(1);
    if(max_correct == correct2)
        answer.push_back(2);
    if(max_correct == correct3)
        answer.push_back(3);
    
    return answer;
}