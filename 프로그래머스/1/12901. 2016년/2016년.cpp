#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int date[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> day = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    
    int cal_date = 0;
    for(int i=1; i<a; i++){
        cal_date += date[i-1];
    }
    
    cal_date += b-1;
    cal_date %= day.size();
    
    answer = day[cal_date];
    
    return answer;
}