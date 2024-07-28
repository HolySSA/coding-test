#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int lux=51, luy=51, rdx=-1, rdy=-1;
    
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#'){
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i+1);
                rdy = max(rdy, j+1);
            }      
        }
    }
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    
    return answer;
}