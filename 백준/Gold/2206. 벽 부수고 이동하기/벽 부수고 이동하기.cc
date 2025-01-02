#include <iostream>
#include <queue>
using namespace std;

struct Info {
    int r;
    int c;
    int wall;
};

int n, m;
int map[1000][1000];
int result[1000][1000];
bool visited[1000][1000][2]; // 벽을 뚫었을 때 / 안 뚫었을 때

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

void Move() {
    queue<Info> q;
    q.push({ 0, 0, 0 });
    result[0][0] = 1;
    visited[0][0][0] = true;
    visited[0][0][1] = true;

    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int cwall = q.front().wall;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            // 벽이고 부순적이 없으면서 방문안한곳 
            if (map[nr][nc] == 1 && cwall == 0 && !visited[nr][nc][1]) {
                visited[nr][nc][1] = true;
                result[nr][nc] = result[cr][cc] + 1;
                q.push({ nr, nc, 1 });
            }
            //벽이 아니고 방문 안한곳
            if (map[nr][nc] == 0 && !visited[nr][nc][cwall]) {
                visited[nr][nc][cwall] = true;
                result[nr][nc] = result[cr][cc] + 1;
                q.push({ nr, nc, cwall });
            }
            //목표에 도착했을 경우
            if (nr == n - 1 && nc == m - 1) {
                cout << result[nr][nc];
                return;
            }
        }
    }

    cout << -1;
    return;
}

int main() {
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    Move();
    return 0;
}
