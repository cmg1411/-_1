#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

char a[55][55];
bool check[55][55];
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool dfs(int x, int y, int px, int py, char col){
    if(check[x][y]) return true;
    check[x][y]=true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m){
            if(a[nx][ny]==col){
                if (!(nx==px && ny==py)){
                    if(dfs(nx,ny,x,y,col))
                        return true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(check[i][j]) continue;
            bool flag = dfs(i, j, -1, -1, a[i][j]);
            if(flag){
                cout << "Yes";
                return 0;
            }
        }
    }
    
    cout << "No";
    return 0;
}
