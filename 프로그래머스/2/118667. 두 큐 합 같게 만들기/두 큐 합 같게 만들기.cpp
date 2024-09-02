#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    int cnt=0, maxLeng=queue1.size()+queue2.size();
    
    vector<int> total_queue;
    long long sum1=0, sum2=0;
    for(auto q: queue1){
        sum1 += q;
        total_queue.push_back(q);
    }
    for(auto q: queue2){
        sum2 += q;
        total_queue.push_back(q);
    }
    
    int s1=0, e1=queue1.size()-1, s2=queue1.size(), e2=maxLeng-1;
    while(cnt <= maxLeng*2){
        if(sum1<sum2){
            sum2 -= total_queue[s2++ % maxLeng];
            sum1 += total_queue[++e1 % maxLeng];
        }
        else if(sum2<sum1){
            sum1 -= total_queue[s1++ % maxLeng];
            sum2 += total_queue[++e2 % maxLeng];
        }
        else{
            answer = cnt;
            break;
        }
        
        cnt++;
    }
    
    return answer;
}