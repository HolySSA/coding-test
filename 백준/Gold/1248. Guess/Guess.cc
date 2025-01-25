#include<iostream>
using namespace std;

int n;
int num[10];
char sign[10][10];

bool Check(int idx) {
    int check = 0;
    for (int i = idx; i >= 0; i--) {
        check += num[i];
        if (check > 0 && sign[i][idx] != '+')
            return false;
        if (check < 0 && sign[i][idx] != '-')
            return false;
        if (check == 0 && sign[i][idx] != '0')
            return false;
    }

    return true;
}

void DFS(int cnt) {
    if (cnt == n) {
        for (int i = 0; i < n; i++)
            cout << num[i] << ' ';

        exit(0);
    }

    for (int i = -10; i <= 10; i++) {
        num[cnt] = i;

        if (Check(cnt))
            DFS(cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
            cin >> sign[i][j];
    }

    DFS(0);

    return 0;
}