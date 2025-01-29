#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, answer = 0;
vector<pair<int, int>> lecture;

bool Comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    cin >> n;
    lecture.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lecture[i].first >> lecture[i].second;
    }

    sort(lecture.begin(), lecture.end(), Comp);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto &lec : lecture) {
        pq.push(lec.first);
        if (pq.size() > lec.second) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
    return 0;
}
