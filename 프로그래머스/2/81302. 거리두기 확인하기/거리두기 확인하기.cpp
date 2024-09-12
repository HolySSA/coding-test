#include <string>
#include <vector>

using namespace std;

bool Distance(int r, int c, vector<string> place) {
    if(r + 1 < place.size()) {
        if(place[r+1][c] == 'P')
            return false;
    }
    if(r + 2 < place.size()) {
        if(place[r+1][c] != 'X' && place[r+2][c] == 'P')
            return false;
    }
    if(r + 1 < place.size() && c - 1 >= 0) {
        if(place[r+1][c-1] == 'P') {
            if(place[r+1][c] != 'X' || place[r][c-1] != 'X')
                return false;
        }
    }
    if(r + 1 < place.size() && c + 1 < place[0].length()) {
        if(place[r+1][c+1] == 'P') {
            if(place[r+1][c] != 'X' || place[r][c+1] != 'X')
                return false;
        }
    }
    if(c + 1 <place[0].length()) {
        if(place[r][c+1] == 'P')
            return false;
    }
    if(c + 2 < place[0].length()) {
        if(place[r][c+1] != 'X' && place[r][c+2] == 'P')
            return false;
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto place: places) {
        bool check = false;
        for(int r = 0; r < place.size(); r++) {
            for(int c = 0; c < place[r].length(); c++) {
                if(place[r][c] == 'P') {
                    if(!Distance(r, c, place))
                        check = true;
                }
            }
        }
        
        if(check)
            answer.push_back(0);
        else
            answer.push_back(1);
    }
    
    return answer;
}