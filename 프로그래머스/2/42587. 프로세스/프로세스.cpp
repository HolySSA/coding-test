#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, bool>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        if (i == location) {
            q.push({ priorities[i], true });
            pq.push(priorities[i]);
            continue;
        }

        q.push({ priorities[i], false });
        pq.push(priorities[i]);
    }

    int max = pq.top();
    while (1) {
        if (q.front().first < max) {
            q.push(q.front());
            q.pop();
        }
        else {
            if (q.front().second) {
                answer++;
                break;
            }

            q.pop();
            pq.pop();
            answer++;

            max = pq.top();
        }
    }
    
    return answer;
}