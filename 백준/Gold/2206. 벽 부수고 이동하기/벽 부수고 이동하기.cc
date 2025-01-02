#include <iostream>
#include <queue>
using namespace std;

typedef struct Info {
    int r;
    int c;
    int wall;
};

int n, m;
int map[1000][1000];
int result[1000][1000];
bool visited[1000][1000][2]; // 벽을 뚫었을 때와 안 뚫었을 때를 따로 체크해야함

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void Move() {
    queue<Info> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    result[0][0] = 1;

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int wall = q.front().wall;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            // 벽이고 부순적이 없으면서 방문안한곳 
            if (map[nr][nc] == 1 && wall == 0 && !visited[nr][nc][wall + 1]) {
                visited[nr][nc][wall + 1] = true;
                result[nr][nc] = result[r][c] + 1;
                q.push({ nr, nc, wall + 1 });
            }
            //벽이 아니고 방문 안한곳
            if (map[nr][nc] != 1 && !visited[nr][nc][wall]) {
                visited[nr][nc][wall] = true;
                result[nr][nc] = result[r][c] + 1;
                q.push({ nr, nc, wall });
            }
            //목표에 도착했을 경우
            if (nr == n - 1 && nc == m - 1) {
                cout << result[nr][nc] << '\n';
                return;
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 1 << '\n';
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