#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer; 
    pair<int, int> start;
    
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].length(); j++){
            if(park[i][j] == 'S'){
                start = make_pair(i, j);
                break;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        pair<int, int> tmp = start;
        bool check = false;
        int n = stoi(routes[i].substr(routes[i].find(' ')+1, routes[i].length()));
        
        if(routes[i][0] == 'E'){
            for(int j=0; j<n; j++){
                if(start.second == park[0].length()-1 || park[start.first][start.second+1] == 'X'){
                    check = true;
                    break;
                }
                
                start.second++;
            }
        }
        if(routes[i][0] == 'W'){
            for(int j=0; j<n; j++){
                if(start.second == 0 || park[start.first][start.second-1] == 'X'){
                    check = true;
                    break;
                }
                
                start.second--;
            }
        }
        if(routes[i][0] == 'N'){
            for(int j=0; j<n; j++){
                if(start.first == 0 || park[start.first-1][start.second] == 'X'){
                    check = true;
                    break;
                }
                
                start.first--;
            }
        }
        if(routes[i][0] == 'S'){
            for(int j=0; j<n; j++){
                if(start.first == park.size()-1 || park[start.first+1][start.second] == 'X'){
                    check = true;
                    break;
                }
                
                start.first++;
            }
        }
        
        if(check)
            start=tmp;
    }
    
    answer.push_back(start.first);
    answer.push_back(start.second);
    
    return answer;
}