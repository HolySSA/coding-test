#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a>b;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++)
        answer.push_back(arr[i]);
    
    int min_index = min_element(answer.begin(), answer.end()) - answer.begin();
    answer.erase(answer.begin() + min_index);

    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}