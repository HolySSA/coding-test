// 11728 배열 합치기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<int>a(n);
    vector<int>b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < b.size(); i++)
        a.push_back(b[i]);

    sort(a.begin(), a.end());

    for (int i : a) {
        cout << i << " ";
    }

    return 0;
}