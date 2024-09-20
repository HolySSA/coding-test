#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int column;

bool Comp(vector<int> a, vector<int> b) {
    if(a[column] == b[column])
        return a[0] > b[0];
    
    return a[column] < b[column];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col - 1;
    
    sort(data.begin(), data.end(), Comp);
    for(int i = row_begin; i <= row_end; i++) {
        int sum = 0;
        for(auto d: data[i-1]) {
            sum += d % i;
        }
        
        answer ^= sum;
    }
    
    return answer;
}