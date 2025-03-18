#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string maxAns = "0", minAns = "9999999999";
vector<char> v;
bool visited[10];

void Calculate(int idx, string ans) {
    if (idx == n) {
        maxAns = max(maxAns, ans);
        minAns = min(minAns, ans);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (visited[i])
            continue;
        if (v[idx] == '<' && ans.back() - '0' >= i)
            continue;
        if (v[idx] == '>' && ans.back() - '0' <= i)
            continue;

        visited[i] = true;
        Calculate(idx + 1, ans + to_string(i));
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i <= 9; i++) {
        visited[i] = true;
        Calculate(0, to_string(i));
        visited[i] = false;
    }

    cout << maxAns << "\n" << minAns;
    return 0;
}
