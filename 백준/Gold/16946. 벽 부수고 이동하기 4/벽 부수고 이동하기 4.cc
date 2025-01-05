#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

struct Pos {
    int r, c;
};

int n, m;
int map[1000][1000];
int result[1000][1000];
int region[1000][1000];
int regionSize[1000000];
bool visited[1000][1000];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int calculateRegion(int r, int c, int id) {
    queue<Pos> q;
    q.push({ r, c });
    visited[r][c] = true;
    region[r][c] = id;

    int cnt = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;
            if (map[nr][nc] == 1 || visited[nr][nc])
                continue;

            q.push({ nr, nc });
            visited[nr][nc] = true;
            region[nr][nc] = id;
            cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    memset(region, -1, sizeof(region)); 
    int regionID = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && region[i][j] == -1) {
                regionSize[regionID] = calculateRegion(i, j, regionID);
                regionID++;
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (map[r][c] == 1) {
                set<int> uniqueRegions;
                int total = 1;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;

                    int neighborID = region[nr][nc];
                    if (neighborID != -1 && uniqueRegions.find(neighborID) == uniqueRegions.end()) {
                        uniqueRegions.insert(neighborID);
                        total += regionSize[neighborID];
                    }
                }

                result[r][c] = total % 10;
            }
            else
                result[r][c] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j];
        }
        cout << '\n';
    }

    return 0;
}
