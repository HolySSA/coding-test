#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int arr1_row = arr1[0].size();
    int arr2_row = arr2[0].size();
    int height = arr1.size();
    
    for(int i=0; i<height; i++){
        vector<int> tmp;
        for(int j=0; j<arr2_row; j++){
            int sum = 0;
            for(int k=0; k<arr1_row; k++)
                sum += arr1[i][k] * arr2[k][j];
            
            tmp.push_back(sum);
        }
        
        answer.push_back(tmp);
    }
    
    return answer;
}