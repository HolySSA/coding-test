#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    int distanceX = 0, distanceY = 0, tmp = 0;
    for(auto ball: balls) {
        int distance = 2e9;
        distanceX = pow(startX - ball[0], 2);
        distanceY = pow(startY - ball[1], 2);
        
        if(startX != ball[0]) {
            tmp = distanceX + pow(startY + ball[1], 2); // 아래 쿠션
            distance = min(distance, tmp); 
            
            tmp = distanceX + pow((n - startY) + (n - ball[1]), 2); // 위 쿠션
            distance = min(distance, tmp);
        }
        else {
            if(startY < ball[1]) {
                tmp = distanceX + pow(startY + ball[1], 2); // 아래 쿠션
                distance = min(distance, tmp); 
            }
            else {
                tmp = distanceX + pow((n - startY) + (n - ball[1]), 2); // 위 쿠션
                distance = min(distance, tmp);
            }
        }
        
        if(startY != ball[1]) {
            tmp = distanceY + pow(startX + ball[0], 2); // 왼 쿠션
            distance = min(distance, tmp); 
            
            tmp = distanceY + pow((m - startX) + (m - ball[0]), 2); // 오른 쿠션
            distance = min(distance, tmp);
        }
        else {
            if(startX < ball[0]) {
                tmp = distanceY + pow(startX + ball[0], 2); // 왼 쿠션
                distance = min(distance, tmp);
            }
            else {
                tmp = distanceY + pow((m - startX) + (m - ball[0]), 2); // 오른 쿠션
                distance = min(distance, tmp);
            }
        }
        
        answer.push_back(distance);
    }
    
    return answer;
}