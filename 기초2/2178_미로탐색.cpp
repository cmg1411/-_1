#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int sq[101][101];
int check[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,m;

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(check[nx][ny]==0 && sq[nx][ny]==1){
                    check[nx][ny]=check[x][y]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    string str;
    for(int i=0 ; i<n ; i++){
        cin >> str;
        for(int j=0 ; j<m ; j++){
            sq[i][j] = str[j]-'0';
        }
    }

    if(sq[0][0]==1){
        bfs(0,0);
    }

    cout << check[n-1][m-1];

    return 0;
}