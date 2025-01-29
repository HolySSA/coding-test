#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, answer = 0;
vector<pair<int, int>> lecture;
priority_queue<int, vector<int>, greater<int>> pq;

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

    // 선택한 강의 갯수(pq.size())-강의 가능일(lec.second) 비교
    for (auto& lec : lecture) {
        pq.push(lec.first);
        if (pq.size() > lec.second)
            pq.pop();
    }

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
    return 0;
}
