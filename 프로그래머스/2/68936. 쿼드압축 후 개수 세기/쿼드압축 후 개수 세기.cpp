#include <string>
#include <vector>

using namespace std;

int one=0, zero=0;

void Check(int x, int y, int size, vector<vector<int>> &arr) {
    if(size == 0)
        return;
    
    bool zero_check = true, one_check = true;
    
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(arr[i][j] == 1)
                zero_check = false;
            if(arr[i][j] == 0)
                one_check = false;
            
            if(!(zero_check || one_check))
                break;
        }
        
        if(!(zero_check || one_check))
            break;
    }
    
    if(zero_check){
        zero++;
        return;
    }
    if(one_check){
        one++;
        return;
    }
    
    Check(x, y, size/2, arr);
    Check(x+size/2, y, size/2, arr);
    Check(x, y+size/2, size/2, arr);
    Check(x+size/2, y+size/2, size/2, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    Check(0, 0, arr.size(), arr);
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}