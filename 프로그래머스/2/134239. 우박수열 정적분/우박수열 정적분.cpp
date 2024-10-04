#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> areas;
    
    while(k != 1) {
        if(k % 2 == 0) {
            k /= 2;
            areas.push_back((double)(k * 1.5));
        }
        else {
            int tmp = k;
            k = k * 3 + 1;
            areas.push_back((double)tmp + ((double)(k - tmp) * 0.5));
        }
        
        //cout<<areas.back()<<' ';
    }
    
    //cout<<'\n';
    
    for(auto range: ranges) {
        int start = range[0];
        int finish = areas.size() + range[1];
        
        //cout<<start<<' '<<finish<<'\n';
        
        if(finish < start) {
            answer.push_back(-1.0);
            continue;
        }
        if(finish == start) {
            answer.push_back(0.0);
            continue;
        }
        
        double sum = 0;
        for(int i = start; i < finish; i++) {
            sum += areas[i];
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}