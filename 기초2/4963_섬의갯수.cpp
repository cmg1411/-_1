#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int is[51][51];
int check[51][51];
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

void bfs(int w, int h, int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y]=1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0 ; i<8 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<w && 0<=ny && ny<h){
                if(check[nx][ny]==0 && is[nx][ny]!=0){
                    check[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while(1){
        int w, h;
        cin >> h >> w;
        if(w==0 && h==0) break;
        memset(is, 0, sizeof(is)); //2차원 배열도 cstring에서 사용, memset(배열이름, 초기화할 값, 배열 크기)
        memset(check, 0, sizeof(check));
        for(int i=0 ; i<w ; i++){
            for(int j=0 ; j<h ; j++){
                cin >> is[i][j];
            }
        }

        int ans=0;
        for(int i=0 ; i<w ; i++){
            for(int j=0 ; j<h ; j++){
                if(check[i][j]==0 && is[i][j]!=0){
                    ans++;
                    bfs(w, h, i, j);
                }
            }
        }

        cout << ans << '\n';
    }


    return 0;
}