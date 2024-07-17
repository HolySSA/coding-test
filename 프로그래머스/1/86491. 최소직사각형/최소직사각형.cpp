#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_width = 0;
    int max_height = 0;
    
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            max_width = max(sizes[i][1], max_width); 
            max_height = max(sizes[i][0], max_height);
        }
        else{
            max_width = max(sizes[i][0], max_width); 
            max_height = max(sizes[i][1], max_height);
        }
    }
    
    answer = max_width*max_height;
    
    return answer;
}