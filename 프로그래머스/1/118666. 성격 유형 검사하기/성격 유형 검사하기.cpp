#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int rt=0, cf=0, jm=0, an=0;
    
    for(int i=0; i<survey.size(); i++){
        switch (survey[i][0]){
            case 'R':
                rt -= choices[i] - 4;
                break;
            case 'T':
                rt += choices[i] - 4;
                break;
            case 'C':
                cf -= choices[i] - 4;
                break;
            case 'F':
                cf += choices[i] - 4;
                break;
            case 'J':
                jm -= choices[i] - 4;
                break;
            case 'M':
                jm += choices[i] - 4;
                break;
            case 'A':
                an -= choices[i] - 4;
                break;
            case 'N':
                an += choices[i] - 4;
                break;
        }
    }
    
    if(rt >= 0)
        answer += 'R';
    else
        answer += 'T';
    
    if(cf >= 0)
        answer += 'C';
    else
        answer += 'F';
    
    if(jm >= 0)
        answer += 'J';
    else
        answer += 'M';
    
    if(an >= 0)
        answer += 'A';
    else
        answer += 'N';
    
    return answer;
}