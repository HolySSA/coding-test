// 10026 적록색약
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Pos {
    int r, c;
};

int n, ans1 = 0, ans2 = 0;
char map[100][100];
bool visited[100][100];

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Area(int r, int c)
{
    queue<Pos> q;
    q.push({ r, c });
    visited[r][c] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                continue;
            if (visited[nr][nc])
                continue;
            
            if (map[nr][nc] == map[cur.r][cur.c])
            {
                q.push({ nr, nc });
                visited[nr][nc] = true;
            }         
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                Area(i, j);
                ans1++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'R')
                map[i][j] = 'G';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                Area(i, j);
                ans2++;
            }
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}
