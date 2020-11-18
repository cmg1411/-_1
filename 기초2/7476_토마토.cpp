#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


int n,m;
int box[1001][1001];
int check[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    queue<pair<int, int> > q;
    int x, y;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> box[i][j];
            if(box[i][j]==1){
                q.push(make_pair(i, j));
                check[i][j]=1;
            }
            if(box[i][j]==-1){
                check[i][j]=-1;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(check[nx][ny]==0 && box[nx][ny]==0){
                    check[nx][ny] = check[x][y]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int ans = -987654321;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(check[i][j]==0){
                cout << -1;
                return 0;
            }
            if(check[i][j]>ans) ans=check[i][j];
        }
    }

    cout << ans-1;

    return 0;
}