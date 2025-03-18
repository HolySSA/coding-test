#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, complex=1, tmp=0;
int house[25][25] = {0, };
bool visited[25][25] = {false, };
vector<int> houseNum;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void DFS(int row, int col){
    visited[row][col] = true;
    tmp++;

    for(int i=0; i<4; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
 
        if(house[nx][ny] == 1 && !visited[nx][ny]) {
            DFS(nx, ny);
        }
    }
}

int main(){
    cin>>n;
    
    for(int i=0; i<n; i++){
        string str; cin>>str;
        for(int j=0; j<n; j++)
            house[i][j] = str[j] - '0';
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && house[i][j] == 1){
                DFS(i, j);
                complex++;
                houseNum.push_back(tmp);
                tmp = 0;
            }
        }
    }
    
    sort(houseNum.begin(), houseNum.end());
    
    cout<<complex-1<<'\n';
    for(int i=0; i<houseNum.size(); i++)
        cout<<houseNum[i]<<'\n';  
    
    return 0;
}