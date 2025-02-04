// 1963 소수 경로
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std;

#define MAX 10000

bool prime[MAX];
bool Visit[MAX];

int start, finish;

void Calculate()
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    Visit[start] = true;

    while (q.empty() == 0)
    {
        int Cur_Num = q.front().first;
        int Cnt = q.front().second;
        q.pop();

        if (Cur_Num == finish)
        {
            cout << Cnt << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                string s = to_string(Cur_Num);
                s[i] = j + '0';
                int nnum; nnum = stoi(s);

                if (prime[nnum] == false)
                    continue;
                if (Visit[nnum] == true)
                    continue;
                if (nnum > 9999 || nnum < 1000)
                    continue;

                Visit[nnum] = true;
                q.push(make_pair(nnum, Cnt + 1));
            }
        }
    }
    cout << "Impossible" << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;

    memset(prime, true, sizeof(prime));
    for (int i = 2; i < MAX; i++)
    {
        for (int j = 2; i * j < MAX; j++)
        {
            prime[i * j] = false;
        }
    }

    for (int i = 0; i < t; i++)
    {
        cin >> start >> finish;
        Calculate();
        memset(Visit, false, sizeof(Visit));
    }

    return 0;
}
